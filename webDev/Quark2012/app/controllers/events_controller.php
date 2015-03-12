<?php
class EventsController extends AppController {

    var $name = 'Events';
    var $helpers = array('Html', 'Form', 'Parser');

    function index() {
        $this->Event->recursive = 0;
        $this->set('events', $this->paginate());
    }

    function admin_index() {
        $this->Event->recursive = 1;
        $this->set('events', $this->paginate());
    }

    function admin_view($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid Event.', true));
            $this->redirect(array('action'=>'index'));
        }
        $this->set('event', $this->Event->read(null, $id));
    }

    function admin_add() {
        if (!empty($this->data)) {
            $this->Event->create();
            if ($this->Event->save($this->data)) {
                $this->Session->setFlash(__('The Event has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The Event could not be saved. Please, try again.', true));
            }
        }
        $categories = $this->Event->Category->find('list');
        $this->set(compact('categories'));
    }

    function admin_edit($id = null) {
        if (!$id && empty($this->data)) {
            $this->Session->setFlash(__('Invalid Event', true));
            $this->redirect(array('action'=>'index'));
        }
        if (!empty($this->data)) {
            if ($this->Event->save($this->data)) {
                $this->Session->setFlash(__('The Event has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The Event could not be saved. Please, try again.', true));
            }
        }
        if (empty($this->data)) {
            $this->data = $this->Event->read(null, $id);
        }
        $categories = $this->Event->Category->find('list');
        $this->set(compact('categories'));
    }

    function admin_delete($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid id for Event', true));
            $this->redirect(array('action'=>'index'));
        }
        if ($this->Event->del($id)) {
            $this->Session->setFlash(__('Event deleted', true));
            $this->redirect(array('action'=>'index'));
        }
    }

    function admin_teams($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid Event.', true));
            $this->redirect(array('action'=>'index'));
        }
        $this->Category->unbindModel( array('hasMany' => array('Events')));
        $this->Event->unbindModel(array('belongsTo' => array('Category')));
        $this->Event->Team->unbindModel(array('belongsTo' => array('Event')));
        $this->Event->Team->unbindModel(array('hasMany' => array('Invite')));
        $event = $this->Event->find('first', array('conditions' => array('Event.id' => $id), 'recursive' => 3));
        $this->set('eventId', $id);
        $this->set('teams', $event['Team']);
    }

    function admin_teams_csv($id = null, $userRole = null) {
        $this->layout = false;
        if (!$id) {
            $this->Session->setFlash(__('Invalid Event.', true));
            $this->redirect(array('action'=>'index'));
        }
        $this->Category->unbindModel( array('hasMany' => array('Events')));
        $this->Event->unbindModel(array('belongsTo' => array('Category')));
        $this->Event->Team->unbindModel(array('belongsTo' => array('Event')));
        $this->Event->Team->unbindModel(array('hasMany' => array('Invite')));
        $event = $this->Event->find('first', array('conditions' => array('Event.id' => $id), 'recursive' => 3));
        $this->set('userRole', $userRole);
        $this->set('teams', $event['Team']);
    }

}
?>