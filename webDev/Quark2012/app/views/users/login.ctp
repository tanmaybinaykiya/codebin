<?php echo $html->css('form', false); ?>
<h1>Login</h1>
<?php
    $session->flash('auth');
    echo $form->create('User', array('action' => 'login', 'class' => 'form'));
    echo $form->input('email');
    echo $form->input('password');
    echo $form->end('Log In');
    
?>
<br clear="all"/>
<br clear="all"/>
<div style="padding-left: 40px">Forgot your password?
<?php echo $html->link(' Click here', '/users/resetpwdmail'); ?>
</div>