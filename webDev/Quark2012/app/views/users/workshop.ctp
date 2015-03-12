<?php echo $html->css('form', false); ?>
<h2>Workshop Registration</h2>
<?php
    echo $form->create('Workshop', array('class' => 'form', 'url' => '/users/workshop'));
    echo $form->input('workshop_id', array('options' => $workshopArray));
    echo $form->end('Submit');
?>