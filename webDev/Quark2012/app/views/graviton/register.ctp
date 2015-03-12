<?php echo $html->css('form', false); ?>
<?php echo $javascript->link('graviton'); ?>
<h1>Graviton Registration Form</h1>
<?php if (!empty($gravitonWorkshops)): ?>
	<strong>I would like to register for:</strong><br />
	<?php echo $form->select('graviton_route', $gravitonWorkshops, null, array(), false); ?>
	<br /><br />
	<?php echo $form->button('Submit', array('id' => 'graviton_register_jump')); ?>
<?php else: ?>
	<h2><?php echo Inflector::humanize($gravitonWorkshop['GravitonWorkshop']['route']); ?></h2>
	<?php if (count($gravitonCentres) == 0): ?>
		<div class="info-box">There are currently no Graviton Centres open for this workshop.</div>
	<?php else: ?>
		<?php
			echo $form->create('GravitonTeam', array('url' => array('controller' => 'graviton', 'action' => 'register', $gravitonWorkshop['GravitonWorkshop']['route']), 'class' => 'form'));
			echo $form->input('GravitonTeam.name', array('label' => 'Team Name', 'after' => ' (optional)'));
			echo $form->input('GravitonTeam.graviton_centre_id', array('options' => $gravitonCentres));
			for ($i = 0; $i < $gravitonWorkshop['GravitonWorkshop']['max_members']; $i++) {
				if ($gravitonWorkshop['GravitonWorkshop']['max_members'] > 1) { 
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
					if ($i == $gravitonWorkshop['GravitonWorkshop']['max_members'] - 1) {
					?>
						<br />(Optional)
					<?php
					}
				}
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
	<?php endif; ?>
<?php endif; ?>