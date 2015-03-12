<?php echo $html->css('form', false); ?>
<h2>Team Workshop Registration</h2>
<h3>Enter quark ids of all members (including you)</h3>
<?php
    echo $form->create('Workshop', array('class' => 'form', 'url' => '/users/team_workshop/'.$id));
   
    for($i=0;$i<$member_no;$i++){
        echo $form->input('quark_id_'.($i+1),array('name' => 'data[Workshop][quark_id]['.$i.']'));
    }

    echo $form->end('Submit');
?>