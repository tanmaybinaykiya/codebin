<?php echo $html->css('form', false); ?>
<h1>Graviton Registration Form</h1>
<?php
	echo $form->create('GravitonTeam', array('action' => 'register', 'class' => 'form'));
	echo $form->input('GravitonTeam.name', array('label' => 'Team Name', 'after' => ' (optional)'));
	echo $form->input('GravitonTeam.graviton_centre_id', array('options' => $gravitonCentres));
	for ($i = 0; $i < 4; $i++) {
		echo '<br />';
		if ($i == 0) {
		?>
			<strong>Team Leader</strong>
			<br />(All correspondance will be given to the leader)
		<?php
		} else {
		?>
			<strong>Member <?php echo ($i + 1); ?></strong>
		<?php
		}
		if ($i == 3) {
		?>
			<br />(Optional)
		<?php
		}
		echo '<br /><br />';
		echo $form->input("GravitonUser.$i.name");
		echo $form->input("GravitonUser.$i.email");
		echo $form->input("GravitonUser.$i.mobile", array('before' => '+91 ', 'size' => '16'));
		echo $form->input("GravitonUser.$i.college_year", array('options' => $collegeYearArray));
		echo $form->input("GravitonUser.$i.college");
		echo $form->input("GravitonUser.$i.city");
		echo $form->input("GravitonUser.$i.state");
	}
	echo $form->end('Submit');
?>