<?php echo $javascript->link('autoScroll', false); ?>
<h1>Register for Quark 2012</h1>
<?php if (isset($success) && $success): ?>
	<?php if (isset($mail_sent) && $mail_sent): ?>
		<p>A <strong>verification link</strong> has been sent to your e-mail address. Please click the link to proceed.</p>
		<p>After that, you may login and proceed to register for events.</p>
	<?php else:?>
		<p><strong>Congratulations!</strong> You have successfully registered for Quark 2012.</p>
		<p>Please login and proceed to register for events.</p>
	<?php endif; ?>
<?php else: ?>
    <?php echo $this->element('register'); ?>
<?php endif; ?>
