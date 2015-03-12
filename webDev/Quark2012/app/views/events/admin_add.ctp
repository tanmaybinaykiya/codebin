<div class="events form">
<?php echo $form->create('Event');?>
	<fieldset>
 		<legend><?php __('Add Event');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('intro', array('class' => 'ckeditor'));
		echo $form->input('details', array('class' => 'ckeditor'));
                echo $form->input('rules', array('class' => 'ckeditor'));
                echo $form->input('judging_criteria', array('class' => 'ckeditor'));
                echo $form->input('additional_info', array('class' => 'ckeditor'));
                echo $form->input('contact', array('class' => 'ckeditor'));
		echo $form->input('min_participants');
		echo $form->input('max_participants');
		echo $form->input('route');
		echo $form->input('category_id');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Events', true), array('action'=>'index'));?></li>
	</ul>
</div>
