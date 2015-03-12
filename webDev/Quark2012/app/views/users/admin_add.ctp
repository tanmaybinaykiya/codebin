<div class="users form">
<?php echo $form->create('User');?>
	<fieldset>
 		<legend><?php __('Add User');?></legend>
	<?php
		echo $form->input('email');
		echo $form->input('password');
		echo $form->input('name');
                echo $form->input('gender');
		echo $form->input('mobile');
		echo $form->input('college');
                echo $form->input('address');
                echo $form->input('state');
                echo $form->input('year');
		echo $form->input('id_no');
		echo $form->input('privilege');
		echo $form->input('verify_key');
                echo $form->input('reset_password_key');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Users', true), array('action'=>'index'));?></li>
	</ul>
</div>
