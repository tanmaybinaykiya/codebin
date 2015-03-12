<div class="accommodations form">
<?php echo $form->create('Accommodation');?>
	<fieldset>
 		<legend><?php __('Add Accommodation');?></legend>
	<?php
		echo $form->input('user_id');
                echo $form->input('quark_ids');
		echo $form->input('time_in');
		echo $form->input('time_out');
		echo $form->input('numboys');
                echo $form->input('numgirls');
                echo $form->input('contact_no');
		echo $form->input('alternate_contact_no');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Accommodations', true), array('action' => 'index'));?></li>
		<li><?php echo $html->link(__('List Users', true), array('controller' => 'users', 'action' => 'index')); ?> </li>
		<li><?php echo $html->link(__('New User', true), array('controller' => 'users', 'action' => 'add')); ?> </li>
	</ul>
</div>
