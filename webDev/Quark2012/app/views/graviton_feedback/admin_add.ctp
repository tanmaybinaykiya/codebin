<div class="gravitonFeedback form">
<?php echo $form->create('GravitonFeedback');?>
	<fieldset>
 		<legend><?php __('Add GravitonFeedback');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('email');
		echo $form->input('phone');
		echo $form->input('college');
		echo $form->input('graviton_workshop_id');
		echo $form->input('graviton_centre_id');
		echo $form->input('answer1');
		echo $form->input('answer2');
		echo $form->input('answer3');
		echo $form->input('answer4');
		echo $form->input('answer5');
		echo $form->input('answer6');
		echo $form->input('no_of_kits');
		echo $form->input('comments');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List GravitonFeedback', true), array('action'=>'index'));?></li>
	</ul>
</div>
