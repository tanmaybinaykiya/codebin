<div class="gravitonUsers form">
<?php echo $form->create('GravitonUser');?>
	<fieldset>
 		<legend><?php __('Edit GravitonUser');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('city');
		echo $form->input('name');
		echo $form->input('college');
		echo $form->input('state');
		echo $form->input('email');
		echo $form->input('mobile');
		echo $form->input('member1_name');
		echo $form->input('member1_mobile');
		echo $form->input('member2_name');
		echo $form->input('member2_mobile');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete', $form->value('GravitonUser.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('GravitonUser.id'))); ?></li>
		<li><?php echo $html->link(__('List GravitonUsers', true), array('action'=>'index'));?></li>
	</ul>
</div>
