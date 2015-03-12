<?php
class PagesController extends AppController {

    var $name = 'Pages';
    var $helpers = array('Html', 'Form', 'Parser');
    var $uses = array('Category', 'Event', 'Page', 'User', 'Team', 'Membership', 'Invite', 'Workshop' );

    function beforeFilter() {
        parent::beforeFilter();
        $this->Auth->allow('display');
        
          
    }
    

    function display() {
         
        $path = func_get_args();

        $count = count($path);
        if (!$count) {
            $this->redirect('/');
        }
        $page = $subpage = $title = null;

        if (!empty($path[0])) {
            $page = $path[0];
        }
        if (!empty($path[1])) {
            $subpage = $path[1];
        }
        if (!empty($path[$count - 1])) {
            switch ($path[$count - 1]) {
                case "home":
                    $title = "";
                    break;
                default:
                    $title = Inflector::humanize($path[$count - 1]);
                }
            }

            $route = Inflector::slug(join('/', $path));
            /*add special layout stuff here if($route=="smthg"){$this->layout= "aasd";}*/
            $this->set(compact('page', 'subpage', 'title'));

            // Obtain HTML
            $pageData = $this->Page->fetchByRoute($route);
            if ($pageData == null) {
                // Place Event-Checking before Category-Checking, since the
                // probability of that happening is more (reduces queries)
                $eventData = $this->Event->fetchByRoute($route);
                if ($eventData == null) {
                    $categoryData = $this->Category->fetchByRoute($route);
                    if ($categoryData == null) {
                        $workshopData = $this->Workshop->fetchByRoute($route);
                        if($workshopData == null)
                            $this->render('/errors/missing_view');
                        else
                        {
                            $this->set(compact('workshopData'));
							$this->set('ifworkshop',true);
                            $this->render('/workshops/index');
                        }
                    }
                    else{
                        $this->set(compact('categoryData'));
                        $this->render('/categories/index');
                    }

                } else {
                    $hasRegistered = false;
                    if ($this->Auth->user()) {
                        $this->User->id = $this->Auth->user('id');
                        $hasRegistered = $this->User->hasRegisteredFor($eventData['Event']['id']);
                    }
                    $this->set('hasRegistered', $hasRegistered);
                    $this->set(compact('eventData'));
                      $this->set('if','true');
                    $this->render('/events/index');
                }
            } else {
                $this->set(compact('pageData'));
                // Execute Methods
                if (method_exists($this, $route)) {
                    $this->$route();
                    $this->render($route);
                }
            }
           
        }

        function events() {
            $this->set('categories', $this->Category->find('all'));
        }

        function admin_index() {
            $this->Page->recursive = 0;
            $this->set('pages', $this->paginate('Page'));
        }

        function admin_view($id = null) {
            if (!$id) {
                $this->Session->setFlash(__('Invalid Page.', true));
                $this->redirect(array('action'=>'index'));
            }
            $this->set('page', $this->Page->read(null, $id));
        }

        function admin_add() {
            if (!empty($this->data)) {
                $this->Page->create();
                if ($this->Page->save($this->data)) {
                    $this->Session->setFlash(__('The Page has been saved', true));
                    $this->redirect(array('action'=>'index'));
                } else {
                    $this->Session->setFlash(__('The Page could not be saved. Please, try again.', true));
                }
            }
        }

        function admin_edit($id = null) {
            if (!$id && empty($this->data)) {
                $this->Session->setFlash(__('Invalid Page', true));
                $this->redirect(array('action'=>'index'));
            }
            if (!empty($this->data)) {
                if ($this->Page->save($this->data)) {
                    $this->Session->setFlash(__('The Page has been saved', true));
                    $this->redirect(array('action'=>'index'));
                } else {
                    $this->Session->setFlash(__('The Page could not be saved. Please, try again.', true));
                }
            }
            if (empty($this->data)) {
                $this->data = $this->Page->read(null, $id);
            }
        }

        function admin_delete($id = null) {
            if (!$id) {
                $this->Session->setFlash(__('Invalid id for Page', true));
                $this->redirect(array('action'=>'index'));
            }
            if ($this->Page->del($id)) {
                $this->Session->setFlash(__('Page deleted', true));
                $this->redirect(array('action'=>'index'));
            }
        }

    }
    ?>