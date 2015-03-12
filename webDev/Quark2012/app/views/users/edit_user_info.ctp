<?php if (isset($success) && $success): ?>
    <p>Your information has been updated.</p>
<?php else: ?>
    <h1>Edit Info</h1>
    <?php echo $this->element('edit_user_info'); ?>
<?php endif; ?>