<div class="gravitonWorkshops form">
<?php echo $form->create('GravitonWorkshop', array('url' => array('controller' => 'graviton', 'action' => 'add_workshop'))); ?>
	<fieldset>
 		<legend><?php __('Add Graviton Workshop');?></legend>
	<?php
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
		<li><?php echo $html->link(__('List Graviton Workshops', true), array('action'=>'index'));?></li>
	</ul>
</div>
