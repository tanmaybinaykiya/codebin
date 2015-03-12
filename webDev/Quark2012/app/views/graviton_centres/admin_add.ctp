<div class="gravitonCentres form">
<?php echo $form->create('GravitonCentre');?>
	<fieldset>
 		<legend><?php __('Add GravitonCentre');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('code');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List GravitonCentres', true), array('action'=>'index'));?></li>
		<li><?php echo $html->link(__('List Graviton Teams', true), array('controller'=> 'graviton_teams', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Team', true), array('controller'=> 'graviton_teams', 'action'=>'add')); ?> </li>
	</ul>
</div>
