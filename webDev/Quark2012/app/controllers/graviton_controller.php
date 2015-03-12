<?php
class GravitonController extends AppController {

	var $helpers = array('Html', 'Form');
	var $uses = array('GravitonTeam', 'GravitonUser', 'GravitonCentre', 'GravitonFeedback','GravitonWorkshop', 'Page');
	var $components = array('Email');

	function beforeFilter() {
		parent::beforeFilter();
		$this->Auth->allow('index', 'success', 'feedback', 'thank_you', 'register');
	}

	function index() {
		$this->set('pageData', $this->Page->fetchByRoute('graviton'));
		$this->render('/pages/display');
	}

	function register($route = null) {
		
		if ($route == null) {
			$gravitonWorkshops = $this->GravitonWorkshop->find('list', array('fields' => array('route', 'name')));
			$this->set(compact('gravitonWorkshops'));
		} else {
			$gravitonWorkshop = $this->GravitonWorkshop->find('first', array('conditions' => array('route' => $route)));
			$gravitonCentres = $this->GravitonCentre->find('list', array('conditions' => array('graviton_workshop_id' => $gravitonWorkshop['GravitonWorkshop']['id'], 'status' => 'yet to start')));
			$collegeYearArray = $this->GravitonUser->getEnumValues('college_year');
			$this->set(compact('gravitonWorkshop', 'gravitonCentres', 'collegeYearArray'));
			if (!empty($this->data)) {
				
				if ($gravitonWorkshop['GravitonWorkshop']['max_members'] > 1) {
					$optionalMember = $this->data['GravitonUser'][$gravitonWorkshop['GravitonWorkshop']['max_members'] - 1];
					$removeMemberFlag = true;
					foreach ($optionalMember as $key => $value) {
						if (!empty($optionalMember[$key]) && $key != 'college_year') {
							$removeMemberFlag = false;
							break;
						}
					}
					if ($removeMemberFlag) {
						// Everything is empty, so remove it from validation
						unset($this->data['GravitonUser'][$gravitonWorkshop['GravitonWorkshop']['max_members'] - 1]);
					}
				}
	
				// Fill in numbers
				$newTeamNumber = $this->GravitonTeam->newTeamNumber($this->data['GravitonTeam']['graviton_centre_id']);
				$this->data['GravitonTeam']['number'] = $newTeamNumber;
				foreach ($this->data['GravitonUser'] as $key => $value) {
					$this->data['GravitonUser'][$key]['number'] = $key + 1;
				}
	
				if ($this->GravitonTeam->saveAll($this->data, array('validate' => 'first'))) {
					$this->Email->from = 'Quark 2012 <info@bits-quark.org>';
					$this->Email->to = $this->data['GravitonUser'][0]['name'] . ' <' . $this->data['GravitonUser'][0]['email'] . '>';
					$this->Email->subject = 'Confirmation Email for Graviton Workshop';
					$this->Email->template = 'welcome_graviton';
					$this->Email->sendAs = 'both';
					$this->set('name', $this->data['GravitonUser'][0]['name']);
					$this->set('teamId', $this->GravitonTeam->generateTeamId($this->data['GravitonTeam']['number'], $this->data['GravitonTeam']['graviton_centre_id']));
					$this->set('gravitonCentre', $this->GravitonCentre->field('GravitonCentre.name', array('GravitonCentre.id' => $this->data['GravitonTeam']['graviton_centre_id'])));
					if ($this->Email->send()) {
						$this->Session->setFlash('Thank You! You have successfully registered.');
						$this->redirect(array('action' => 'success'));
					} else {
						$this->Session->setFlash('The mail server doesn\'t seem to be responding. Please try again.');
					}
				} else {
					$this->Session->setFlash('An error occurred with your form submission. Please try again.');
				}
			}
		}
	}

	function success() {
		if (!$this->Session->check('Message.flash')) {
			$this->redirect(array('action' => 'index'));
		}
	}

	function feedback() {
		if (!empty($this->data)) {
			$this->GravitonFeedback->create();
			if ($this->GravitonFeedback->save($this->data)) {
				$this->Session->setFlash(__('Your feedback has been submitted.', true));
				$this->redirect(array('action'=>'thank_you'));
			} else {
				$this->Session->setFlash(__('An error occurred with your form submission. Please, try again.', true));
			}
		}
		$gravitonCentres = $this->GravitonCentre->find('list');
		$this->set(compact('gravitonWorkshops', 'gravitonCentres'));
	}

	function thank_you() {
		if (!$this->Session->check('Message.flash')) {
			$this->redirect(array('action' => 'index'));
		}
	}

	function admin_index() {
		$this->GravitonWorkshop->recursive = 1;
		$this->set('gravitonWorkshops', $this->paginate('GravitonWorkshop'));
	}
	
	function admin_add_workshop() {
		if (!empty($this->data)) {
			$this->GravitonWorkshop->create();
			if ($this->GravitonWorkshop->save($this->data)) {
				$this->Session->setFlash(__('The Graviton Workshop has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Graviton Workshop could not be saved. Please, try again.', true));
			}
		}
	}

	function admin_edit_workshop($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Graviton Workshop', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->GravitonWorkshop->save($this->data)) {
				$this->Session->setFlash(__('The Graviton Workshop has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Graviton Workshop could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->GravitonWorkshop->read(null, $id);
		}
	}

	function admin_delete_workshop($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Graviton Workshop', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->GravitonWorkshop->del($id)) {
			$this->Session->setFlash(__('Graviton Workshop deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function admin_view_centre($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid Graviton Centre.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->GravitonCentre->recursive = 2;
		$this->GravitonCentre->unbindModel(array('belongsTo' => array('GravitonWorkshop')));
		$this->GravitonTeam->unbindModel(array('belongsTo' => array('GravitonCentre')));
		$this->set('gravitonCentre', $this->GravitonCentre->read(null, $id));
	}
	
	function admin_add_centre() {
		if (!empty($this->data)) {
			$this->GravitonCentre->create();
			if ($this->GravitonCentre->save($this->data)) {
				$this->Session->setFlash(__('The Graviton Centre has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Graviton Centre could not be saved. Please, try again.', true));
			}
		}
		$statusArray = $this->GravitonCentre->getEnumValues('status');
		$gravitonWorkshops = $this->GravitonWorkshop->find('list');
		$this->set(compact('statusArray', 'gravitonWorkshops'));
	}
	
	function admin_edit_centre($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Graviton Centre', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->GravitonCentre->save($this->data)) {
				$this->Session->setFlash(__('The Graviton Centre has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Graviton Centre could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->GravitonCentre->read(null, $id);
		}
		$statusArray = $this->GravitonCentre->getEnumValues('status');
		$gravitonWorkshops = $this->GravitonWorkshop->find('list');
		$this->set(compact('statusArray', 'gravitonWorkshops'));
	}

	function admin_delete_centre($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Graviton Centre', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->GravitonCentre->del($id)) {
			$this->Session->setFlash(__('Graviton Centre deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function admin_add_team() {
		if (!empty($this->data)) {
			$this->GravitonTeam->create();
			if ($this->GravitonTeam->save($this->data)) {
				$this->Session->setFlash(__('The GravitonTeam has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The GravitonTeam could not be saved. Please, try again.', true));
			}
		}
		$gravitonCentres = $this->GravitonCentre->find('list');
		$paidArray = $this->GravitonTeam->getEnumValues('paid');
		$this->set(compact('paidArray', 'gravitonCentres'));
	}

	function admin_edit_team($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid GravitonTeam', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->GravitonTeam->save($this->data)) {
				$this->Session->setFlash(__('The GravitonTeam has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The GravitonTeam could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->GravitonTeam->read(null, $id);
		}
		$gravitonCentres = $this->GravitonCentre->find('list');
		$paidArray = $this->GravitonTeam->getEnumValues('paid');
		$this->set(compact('paidArray', 'gravitonCentres'));
	}

	function admin_delete_team($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for GravitonTeam', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->GravitonTeam->del($id)) {
			$this->Session->setFlash(__('GravitonTeam deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function admin_view_user($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid GravitonUser.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('gravitonUser', $this->GravitonUser->read(null, $id));
	}
	
	function admin_add_user() {
		if (!empty($this->data)) {
			$this->GravitonUser->create();
			if ($this->GravitonUser->save($this->data)) {
				$this->Session->setFlash(__('The GravitonUser has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The GravitonUser could not be saved. Please, try again.', true));
			}
		}
		$collegeYearArray = $this->GravitonUser->getEnumValues('college_year');
		$attendedArray = $this->GravitonUser->getEnumValues('attended');
		$gravitonTeams = $this->GravitonTeam->find('list');
		$this->set(compact('gravitonTeams', 'collegeYearArray', 'attendedArray'));
	}

	function admin_edit_user($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid GravitonUser', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->GravitonUser->save($this->data)) {
				$this->Session->setFlash(__('The GravitonUser has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The GravitonUser could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->GravitonUser->read(null, $id);
		}
		$collegeYearArray = $this->GravitonUser->getEnumValues('college_year');
		$attendedArray = $this->GravitonUser->getEnumValues('attended');
		$gravitonTeams = $this->GravitonTeam->find('list');
		$this->set(compact('gravitonTeams', 'collegeYearArray', 'attendedArray'));
	}

	function admin_delete_user($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for GravitonUser', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->GravitonUser->del($id)) {
			$this->Session->setFlash(__('GravitonUser deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function admin_feedback($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid Graviton Centre.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->GravitonFeedback->recursive = 0;
		$this->set('gravitonFeedback', $this->paginate('GravitonFeedback', array('graviton_centre_id' => $id)));
	}
	
	function admin_view_feedback($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid GravitonFeedback.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('gravitonFeedback', $this->GravitonFeedback->read(null, $id));
	}
	
	function admin_edit_feedback($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid GravitonFeedback', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->GravitonFeedback->save($this->data)) {
				$this->Session->setFlash(__('The GravitonFeedback has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The GravitonFeedback could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->GravitonFeedback->read(null, $id);
		}
		//$gravitonWorkshops = $this->GravitonFeedback->GravitonWorkshop->find('list');
		$gravitonCentres = $this->GravitonFeedback->GravitonCentre->find('list');
		$this->set(compact('gravitonWorkshops','gravitonCentres'));
	}

	function admin_delete_feedback($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for GravitonFeedback', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->GravitonFeedback->del($id)) {
			$this->Session->setFlash(__('GravitonFeedback deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
}
?>