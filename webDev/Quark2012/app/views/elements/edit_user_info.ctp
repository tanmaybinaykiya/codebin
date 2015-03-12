<?php echo $html->css('form_reg', false); ?>
<div class="form">
	<?php $options=array('Male'=>'Male','Female'=>'Female');?>
	<?php echo $form->create('User', array('action' => 'edit_user_info')); ?>
	<?php echo $form->input('name', array('label' => 'Full Name', 'size' => '20')); ?>
	<?php echo $form->label('gender'); ?>
	<?php echo $form->select('gender', $options); ?>
	
	<?php echo $form->input('secretword', array('label' => 'Password', 'type' => 'password')); ?>
        <br/>
	<?php echo $form->input('secretword2', array('label' => 'Retype Password', 'type' => 'password')); ?>
        <br/>
	<?php echo $form->label('college'); ?>
	<?php echo $form->select('college', $colleges); ?>
        <br/>
        <?php echo $form->input('othercollege', array('label' => 'Others, type here', 'size' => '70')); ?>
        <br/>
	<?php echo $form->label('address'); ?>
	<?php echo $form->textarea('address', array('size' => '255')); ?>
	<?php echo $form->input('state', array('size' => '30')); ?>
	<?php $yearoptions=array('First Year Undergraduate'=>'First Year Undergraduate','Second Year Undergraduate'=>'Second Year Undergraduate','Third Year Undergraduate'=>'Third Year Undergraduate','Fourth Year Undergraduate'=>'Fourth Year Undergraduate','Fifth Year Undergraduate'=>'Fifth Year Undergraduate','First Year Postgraduate'=>'First Year Postgraduate','Second Year Postgraduate'=>'Second Year Postgraduate','Third Year Postgraduate'=>'Third Year Postgraduate');?>
	<?php echo $form->label('year'); ?>
	<?php echo $form->select('year', $yearoptions); ?>
	<?php echo $form->input('mobile', array('between' => '+91 ')); ?>
	<?php echo $form->end('Submit'); ?>
</div>
<br clear="all" />
