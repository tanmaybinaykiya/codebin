<div class="workshops form">
<?php echo $form->create('Workshop');?>
	<fieldset>
 		<legend><?php __('Edit Workshop');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('name');
		echo $form->input('price');
                echo $form->input('introduction', array('class' => 'ckeditor'));
		echo $form->input('content', array('class' => 'ckeditor'));
                echo $form->input('rules', array('class' => 'ckeditor'));
		echo $form->input('route');
                $options = array('Yes' => 'Yes', 'No' => 'No');
                echo $form->label('team_event');
                echo $form->select('team_event', $options);
                echo $form->input('no_of_members');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action' => 'delete', $form->value('Workshop.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('Workshop.id'))); ?></li>
		<li><?php echo $html->link(__('List Workshops', true), array('action' => 'index'));?></li>
	</ul>
</div>
