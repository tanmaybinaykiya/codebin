<div class="gravitonTeams form">
<?php echo $form->create('GravitonTeam');?>
	<fieldset>
 		<legend><?php __('Edit GravitonTeam');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('graviton_centre_id');
		echo $form->input('name');
		echo $form->input('number');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete', $form->value('GravitonTeam.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('GravitonTeam.id'))); ?></li>
		<li><?php echo $html->link(__('List GravitonTeams', true), array('action'=>'index'));?></li>
	</ul>
</div>
