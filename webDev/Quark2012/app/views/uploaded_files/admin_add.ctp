<div class="uploadedFiles form">
    <h2>Limit on file upload size: 2 MB</h2>
<?php echo $form->create('UploadedFile', array('type' => 'file'));?>
	<fieldset>
 		<legend><?php __('Upload New File');?></legend>
	<?php
		echo $form->label('File');
		echo $form->file('UploadedFile.filedata', array('class' => 'input'));
		echo $form->input('type', array('options' => $typeArray));
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Uploaded Files', true), array('action'=>'index'));?></li>
	</ul>
</div>
