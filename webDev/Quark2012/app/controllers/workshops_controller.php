<?php
class WorkshopsController extends AppController {

    var $name = 'Workshops';
    var $helpers = array('Html', 'Form', 'Parser');

    function index() {
        $this->Workshop->recursive = 0;
        $this->set('workshops', $this->paginate());
    }

    function admin_index() {
        $this->Workshop->recursive = 0;
        $this->set('workshops', $this->paginate());
    }

    function admin_view($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid Workshop.', true));
            $this->redirect(array('action'=>'index'));
        }
        $this->loadModel('WorkshopsUser');
        $this->WorkshopsUser->unbindModel(array('belongsTo' => array('Workshop')));
        $this->Workshop->recursive = 2;
        $this->set('workshop', $this->Workshop->read(null, $id));
    }

    function admin_add() {
        if (!empty($this->data)) {
            $this->Workshop->create();
            if ($this->Workshop->save($this->data)) {
                $this->Session->setFlash(__('The Workshop has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The Workshop could not be saved. Please, try again.', true));
            }
        }
    }

    function admin_edit($id = null) {
        if (!$id && empty($this->data)) {
            $this->Session->setFlash(__('Invalid Workshop', true));
            $this->redirect(array('action'=>'index'));
        }
        if (!empty($this->data)) {
            if ($this->Workshop->save($this->data)) {
                $this->Session->setFlash(__('The Workshop has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The Workshop could not be saved. Please, try again.', true));
            }
        }
        if (empty($this->data)) {
            $this->data = $this->Workshop->read(null, $id);
        }

    }

    function admin_delete($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid id for Workshop', true));
            $this->redirect(array('action'=>'index'));
        }
        if ($this->Workshop->del($id)) {
            $this->Session->setFlash(__('Workshop deleted', true));
            $this->redirect(array('action'=>'index'));
        }
    }

}
?>