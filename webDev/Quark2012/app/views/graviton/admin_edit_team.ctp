<div class="gravitonTeams form">
<?php echo $form->create('GravitonTeam', array('url' => array('controller' => 'graviton', 'action' => 'edit_team'))); ?>
	<fieldset>
 		<legend><?php __('Edit Graviton Team');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('graviton_centre_id');
		echo $form->input('name');
		echo $form->input('number');
		echo $form->input('paid', array('options' => $paidArray));
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete_team', $form->value('GravitonTeam.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('GravitonTeam.id'))); ?></li>
	</ul>
</div>
