<div class="gravitonUsers form">
<?php echo $form->create('GravitonUser', array('url' => array('controller' => 'graviton', 'action' => 'add_user'))); ?>
	<fieldset>
 		<legend><?php __('Add Graviton User');?></legend>
	<?php
		echo $form->input('graviton_team_id', array('options'=> $gravitonTeams));
		echo $form->input('name');
		echo $form->input('email');
		echo $form->input('mobile');
		echo $form->input('college');
		echo $form->input('college_year', array('options' => $collegeYearArray));
		echo $form->input('city');
		echo $form->input('state');
		echo $form->input('number');
		echo $form->input('attended', array('options' => $attendedArray));
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>

