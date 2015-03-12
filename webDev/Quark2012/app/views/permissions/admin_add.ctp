<div class="permissions form">
<?php echo $form->create('Permission');?>
	<fieldset>
 		<legend><?php __('Add Permission');?></legend>
	<?php
		echo $form->input('email');
                echo $form->input('resource', array('options' => $resourceArray));
                echo $form->input('all', array('options' => $trueFalseArray));
		echo $form->input('page_id');
		echo $form->input('category_id');
		echo $form->input('event_id');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Permissions', true), array('action' => 'index'));?></li>
	</ul>
</div>
