<div class="gravitonWorkshops form">
<?php echo $form->create('GravitonWorkshop');?>
	<fieldset>
 		<legend><?php __('Add GravitonWorkshop');?></legend>
	<?php
		echo $form->input('name');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List GravitonWorkshops', true), array('action'=>'index'));?></li>
	</ul>
</div>
