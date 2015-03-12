<div class="pages form">
<?php echo $form->create('Page', array('class' => 'long-form'));?>
	<fieldset>
 		<legend><?php __('Edit Page');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('name');
		echo $form->input('content', array('class' => 'ckeditor'));
		echo $form->input('route');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Delete', true), array('action'=>'delete', $form->value('Page.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('Page.id'))); ?></li>
		<li><?php echo $html->link(__('List Pages', true), array('action'=>'index'));?></li>
	</ul>
</div>
