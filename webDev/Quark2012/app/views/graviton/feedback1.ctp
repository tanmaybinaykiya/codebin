<?php echo $html->css('form', false); ?>
<h1>Graviton Workshop Series</h1>
<h2>Feedback Form</h2>
<div class="gravitonFeedback form">
<?php 
	echo $form->create('GravitonFeedback', array('url' => array('controller' => 'graviton_teams', 'action' => 'feedback'), 'class' => 'long-form'));
	echo $form->input('name');
	echo $form->input('email');
	echo $form->input('phone', array('label' => 'Phone (10-digit mobile)'));
	echo $form->input('college');
	echo $form->input('graviton_centre_id');
	echo $form->input('answer1', array('label' => 'Were there any prerequisites needed for attending the workshop?'));
	echo $form->input('answer2', array('label' => 'Was the material presented clearly and effectively?'));
	echo $form->input('answer3', array('label' => 'How was the technical expertise of the instructors?'));
	echo $form->input('answer4', array('label' => 'How was the time allocation while covering different sections of the course?'));
	echo $form->input('answer5', array('label' => 'How was the quality of the Kits provided?'));
	echo $form->input('answer6', array('label' => 'What workshops would you like to see in the future?'));
	echo $form->input('no_of_kits', array('label' => 'How many kits did you buy? (Number)'));
	echo $form->input('comments', array('label' => 'Suggestions or Comments'));
	echo $form->end('Submit');
?>
</div>