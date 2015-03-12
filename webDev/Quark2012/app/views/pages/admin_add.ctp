<div class="pages form">
<?php echo $form->create('Page');?>
	<fieldset>
 		<legend><?php __('Add Page');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('content', array('class' => 'ckeditor'));
		echo $form->input('route');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Pages', true), array('action'=>'index'));?></li>
	</ul>
</div>
