<div class="colleges form">
<?php echo $form->create('College');?>
	<fieldset>
 		<legend><?php __('Add College');?></legend>
	<?php
		echo $form->input('college');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Colleges', true), array('action' => 'index'));?></li>
	</ul>
</div>
