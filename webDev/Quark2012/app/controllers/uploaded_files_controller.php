<?php
class UploadedFilesController extends AppController {

	var $name = 'UploadedFiles';
	var $helpers = array('Html', 'Form');
	var $components = array('Upload');

	function admin_index() {
		$this->UploadedFile->recursive = 0;
		$this->set('uploadedFiles', $this->paginate());
	}

	function admin_add() {
		$this->set('typeArray', $this->UploadedFile->getEnumValues('type'));
		if (!empty($this->data)) {
			$location = "";
			$rules = null;
			switch ($this->data['UploadedFile']['type']) {
				case 'Picture':
					$location = 'img/uploads/';
					$filename = $this->data['UploadedFile']['filedata']['name'];
					$ext = trim(substr($filename,strrpos($filename,".")+1,strlen($filename)));
					if ($ext == 'jpg' || $ext == 'png' || $ext == 'gif') {
						$rules['type'] = 'resize';
						$rules['size'] = '400';
						$rules['output'] = $ext;
						if ($ext == 'jpg') {
							$rules['quality'] = 100;
						} else {
							$rules['quality'] = 9;
						}
					}
					break;
				default:
					$location = 'files/';
			}
			$destination = realpath('../../app/webroot/' . $location) . '/';
			$file = $this->data['UploadedFile']['filedata'];
			if ($file['size'] > 0) {
				$result = $this->Upload->upload($file, $destination);
				if ($result != false) {
					$this->data['UploadedFile']['name'] = $this->Upload->result;
					$this->data['UploadedFile']['user_id'] = $this->Auth->user('id');
				} else {
					$errors = $this->Upload->errors;
					if(is_array($errors)) {
						$errors = implode("<br />",$errors);
					}
					$this->Session->setFlash($errors);
					return;
				}
				$this->UploadedFile->create();
				if ($this->UploadedFile->save($this->data)) {
					$this->Session->setFlash(__('The File has been saved', true));
					$this->redirect(array('action'=>'index'));
				} else {
					$this->Session->setFlash(__('The File could not be saved. Please, try again.', true));
				}
			} else {
				$this->Session->setFlash(__('You did not upload a File. Please, try again.', true));
			}
		}
	}

//	function admin_delete($id = null) {
//		if (!$id) {
//			$this->Session->setFlash(__('Invalid id for Uploaded File', true));
//			$this->redirect(array('action'=>'index'));
//		}
//		if ($this->UploadedFile->delete($id)) {
//			$this->Session->setFlash(__('File deleted', true));
//			$this->redirect(array('action'=>'index'));
//		}
//	}

        function admin_home() {
            
        }

}
?>