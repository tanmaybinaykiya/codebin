<div class="categories form">
<?php echo $form->create('Category');?>
	<fieldset>
 		<legend><?php __('Add Category');?></legend>
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
		<li><?php echo $html->link(__('List Categories', true), array('action'=>'index'));?></li>
	</ul>
</div>