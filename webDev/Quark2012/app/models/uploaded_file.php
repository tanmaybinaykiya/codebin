<?php
class UploadedFile extends AppModel {

	var $name = 'UploadedFile';

	function delete($id) {
		$uploadedFile = $this->find('first', array('conditions' => array('UploadedFile.id' => $id)));
		if ($this->del($id)) {
			$file = "";
			if ($uploadedFile['UploadedFile']['type'] == 'Picture') {
				$file .= 'img/uploads/';
			} else {
				$file .= 'files/';
			}
			$file .= $uploadedFile['UploadedFile']['name'];
			unlink($file);
			return true;
		}
		return false;
	}
}
?>