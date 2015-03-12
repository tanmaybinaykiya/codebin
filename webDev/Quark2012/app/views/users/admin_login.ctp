<h2>Login</h2>
<?php $session->flash('auth'); ?>
<div class="form">
<?php
	echo $form->create('User', array('action' => 'login'));
	echo $form->input('email');
	echo $form->input('password');
	echo $form->end('Login');
?>
</div>