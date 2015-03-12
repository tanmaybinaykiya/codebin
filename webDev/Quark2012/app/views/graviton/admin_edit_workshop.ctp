<div class="gravitonWorkshops form">
<?php echo $form->create('GravitonWorkshop', array('url' => array('controller' => 'graviton', 'action' => 'edit_workshop'))); ?>
	<fieldset>
 		<legend><?php __('Edit Graviton Workshop');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('name');
		echo $form->input('min_members');
		echo $form->input('max_members');
		echo $form->input('route');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete', $form->value('GravitonWorkshop.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('GravitonWorkshop.id'))); ?></li>
		<li><?php echo $html->link(__('List Graviton Workshops', true), array('action'=>'index'));?></li>
	</ul>
</div>
