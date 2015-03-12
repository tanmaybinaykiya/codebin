<div class="gravitonCentres form">
<?php echo $form->create('GravitonCentre', array('url' => array('controller' => 'graviton', 'action' => 'add_centre'))); ?>
	<fieldset>
 		<legend><?php __('Add Graviton Centre');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('code');
		echo $form->input('status', array('options' => $statusArray));
		echo $form->input('graviton_workshop_id', array('options' => $gravitonWorkshops));
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Graviton Workshops', true), array('controller'=> 'graviton', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Team', true), array('controller'=> 'graviton', 'action'=>'add_team')); ?> </li>
	</ul>
</div>
