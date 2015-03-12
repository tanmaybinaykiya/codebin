<div class="gravitonTeams form">
<?php echo $form->create('GravitonTeam', array('url' => array('controller' => 'graviton', 'action' => 'add_team'))); ?>
	<fieldset>
 		<legend><?php __('Add Graviton Team');?></legend>
	<?php
		echo $form->input('graviton_centre_id');
		echo $form->input('name');
		echo $form->input('number');
		echo $form->input('paid', array('options' => $paidArray));
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
