<h2>Graviton</h2>
<div class="gravitonUsers form">
<?php
echo $form->create('GravitonUser', array('url' => array('controller' => 'graviton_users', 'action' => 'add')));?>
	<?php
		echo $form->input('city');
	?>
	<fieldset>
 	<legend><?php __('Team Leader');?></legend>
	<?php
		echo $form->input('name');
		echo $form->input('college');
		echo $form->input('state');
		echo $form->input('email');
		echo $form->input('mobile');
	?>
	</fieldset>
	<br />
	<fieldset>
	<legend><?php __('Team Member 1');?></legend>
	<?php
		echo $form->input('member1_name');
		echo $form->input('member1_mobile');
	?>
	</fieldset>
	<br />
	<fieldset>
 	<legend><?php __('Team Member 2');?></legend>
	<?php
		echo $form->input('member2_name');
		echo $form->input('member2_mobile');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>