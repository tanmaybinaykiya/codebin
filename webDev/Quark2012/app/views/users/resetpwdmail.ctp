<?php if (isset($displayform) && $displayform): ?>
<h1>Reset your password</h1>
<?php echo $html->css('form', false); ?>
<div class="form">
        <?php echo $form->create('User', array('action' => 'resetpwdmail')); ?>
	<?php echo $form->input('email', array('label' => 'Email Address', 'size' => '30')); ?>
	<?php echo $form->end('Submit'); ?>
</div>
<br clear="all" />
<?php endif; ?>
