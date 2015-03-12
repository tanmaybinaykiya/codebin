<?php
class PermissionsController extends AppController {

	var $name = 'Permissions';
	var $helpers = array('Html', 'Form');
        var $uses = array('Permission', 'Category', 'Event', 'Page');

	function admin_index() {
		$this->Permission->recursive = 1;
                $permissions = $this->paginate('Permission');
                $i = 0;
                foreach ($permissions as $permission) {
                    switch ($permission['Permission']['resource']) {
                        case 'Category':
                            $resource = $this->Category->find('first', array('conditions' => array('id' => $permission['Permission']['resource_id'])));
                            $permissions[$i]['Resource']['name'] = $resource['Category']['name'];
                            break;
                        case 'Event':
                            $resource = $this->Event->find('first', array('conditions' => array('id' => $permission['Permission']['resource_id'])));
                            $permissions[$i]['Resource']['name'] = $resource['Event']['name'];
                            break;
                        case 'Page':
                            $resource = $this->Page->find('first', array('conditions' => array('id' => $permission['Permission']['resource_id'])));
                            $permissions[$i]['Resource']['name'] = $resource['Page']['name'];
                            break;
                        default:
                            $permissions[$i]['Resource']['name'] = 'All';
                    }
                    $i++;
                }
		$this->set('permissions', $permissions);
	}

	function admin_add() {
		if (!empty($this->data)) {
                    $user = $this->Permission->User->find('first', array('conditions' => array('email' => $this->data['Permission']['email'])));
                    if (empty($user)) {
                        $this->Session->setFlash('Failed to locate user.');
                    } else {
                        if ($user['User']['privilege'] == 0) {
                            $user['User']['privilege'] = 1;
                            $this->Permission->User->save($user);
                        }
                        $this->data['Permission']['user_id'] = $user['User']['id'];
                        if ($this->data['Permission']['all'] == 'false') {
                            switch ($this->data['Permission']['resource']) {
                                case 'Category':
                                    $this->data['Permission']['resource_id'] = $this->data['Permission']['category_id'];
                                    break;
                                case 'Event':
                                    $this->data['Permission']['resource_id'] = $this->data['Permission']['event_id'];
                                    break;
                                case 'Page':
                                    $this->data['Permission']['resource_id'] = $this->data['Permission']['page_id'];
                                    break;
                            }
                        }
                        $this->Permission->create();
                        if ($this->Permission->save($this->data)) {
                                $this->Session->setFlash(__('The Permission has been saved', true));
                                $this->redirect(array('action'=>'index'));
                        } else {
                                $this->Session->setFlash(__('The Permission could not be saved. Please, try again.', true));
                        }
                    }
		}
		$pages = $this->Page->find('list');
                $categories = $this->Category->find('list');
                $events = $this->Event->find('list');
                $resourceArray = $this->Permission->getEnumValues('resource');
                $trueFalseArray = array(
                    'false' => 'false',
                    'true' => 'true'
                );
		$this->set(compact('pages', 'categories', 'events', 'resourceArray', 'trueFalseArray'));
	}

	function admin_delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Permission', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Permission->del($id)) {
			$this->Session->setFlash(__('Permission deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}

}
?>