<?php
class CollegesController extends AppController {

	var $name = 'Colleges';
	var $helpers = array('Html', 'Form','Parser');

	function admin_index() {
		$this->College->recursive = 1;
		$this->set('colleges', $this->paginate());
	}

	function admin_view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid College.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('college', $this->College->read(null, $id));
	}

	function admin_add() {
		if (!empty($this->data)) {
			$this->College->create();
			if ($this->College->save($this->data)) {
				$this->Session->setFlash(__('The College has been saved', true));
                                debug($this->data);
				//$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The College could not be saved. Please, try again.', true));
			}
		}
	}

	function admin_edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid College', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->College->save($this->data)) {
				$this->Session->setFlash(__('The College has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The College could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->College->read(null, $id);
		}
	}

	function admin_delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for College', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->College->del($id)) {
			$this->Session->setFlash(__('College deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
        function admin_import() {
		// to avoid having to tweak the contents of
 		// $data you should use your db field name as the heading name
		// eg: Post.id, Post.title, Post.description

		// set the filename to read CSV from

                $filename="../../app/webroot/colleges.csv";
		// open the file
 		$handle = fopen($filename, "r");
                
 		// read the 1st row as headings
 		$header = fgetcsv($handle);
                
		// create a message container
		$return = array(
			'messages' => array(),
			'errors' => array(),
		);

 		// read each data row in the file
 		while (($row = fgetcsv($handle)) !== FALSE) {
 			//$i++;
 			$data = array();

 			// for each header field
 			foreach ($header as $k=>$head) {
 				// get the data field from Model.field
 				if (strpos($head,'.')!==false) {
	 				$h = explode('.',$head);
	 				$data[$h[0]][$h[1]]=(isset($row[$k])) ? $row[$k] : '';
				}
 				// get the data field from field
				else {
	 				$data['College'][$head]=(isset($row[$k])) ? $row[$k] : '';
				}
 			}

                        //debug($data);


                        $this->College->create();
			if ($this->College->save($data)) {
				$this->Session->setFlash(__('The College has been saved', true));
				
			} else {
				$this->Session->setFlash(__('The College could not be saved. Please, try again.', true));
			}


			// see what we have
			// debug($data);

 			// validate the row
			/*$this->set($data);
			if (!$this->validates()) {

				$this->Session->setFlash('Post for Row'.$i.' failed to validate.');
			}

 			// save the row
			if (!$error && !$this->save($data)) {
                            $this->Session->setFlash('Post for Row'.$i.' failed to save.');

				
			}

 			// success message!
			if (!$error) {
                            $this->Session->setFlash('Post for Row'.$i.' was saved.');
				
			}*/
 		}

 		// close the file
 		fclose($handle);

 		// return the messages
 		return $return;
	}


}
?>