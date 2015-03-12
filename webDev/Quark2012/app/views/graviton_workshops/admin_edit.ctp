<div class="gravitonWorkshops form">
<?php echo $form->create('GravitonWorkshop');?>
	<fieldset>
 		<legend><?php __('Edit GravitonWorkshop');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('name');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete', $form->value('GravitonWorkshop.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('GravitonWorkshop.id'))); ?></li>
		<li><?php echo $html->link(__('List GravitonWorkshops', true), array('action'=>'index'));?></li>
	</ul>
</div>
