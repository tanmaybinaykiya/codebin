<div class="gravitonTeams form">
<?php echo $form->create('GravitonTeam');?>
	<fieldset>
 		<legend><?php __('Add GravitonTeam');?></legend>
	<?php
		echo $form->input('graviton_centre_id');
		echo $form->input('name');
		echo $form->input('number');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List GravitonTeams', true), array('action'=>'index'));?></li>
	</ul>
</div>
