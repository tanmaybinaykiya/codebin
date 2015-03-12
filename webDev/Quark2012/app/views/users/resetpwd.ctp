
<?php if (isset($key) && $key): ?>
<h1>Reset your password</h1>
<?php echo $html->css('form', false); ?>
<div class="form">
        <?php   $address='/resetpwd/'.$key;
                
                echo $form->create('User', array('action' => $address)); ?>
	<?php echo $form->input('secretword', array('label' => 'Password', 'type' => 'password')); ?>
	<?php echo $form->input('secretword2', array('label' => 'Retype Password', 'type' => 'password')); ?>
	<?php echo $form->end('Submit'); ?>
</div>
<br clear="all" />
<?php endif; ?>
