<div class="colleges form">
<?php echo $form->create('College');?>
	<fieldset>
 		<legend><?php __('Edit College');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('college');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action' => 'delete', $form->value('College.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('College.id'))); ?></li>
		<li><?php echo $html->link(__('List Colleges', true), array('action' => 'index'));?></li>
	</ul>
</div>
