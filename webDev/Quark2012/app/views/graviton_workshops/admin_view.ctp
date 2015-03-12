<div class="gravitonWorkshops view">
<h2><?php  __('GravitonWorkshop');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonWorkshop['GravitonWorkshop']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Name'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonWorkshop['GravitonWorkshop']['name']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Edit GravitonWorkshop', true), array('action'=>'edit', $gravitonWorkshop['GravitonWorkshop']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete GravitonWorkshop', true), array('action'=>'delete', $gravitonWorkshop['GravitonWorkshop']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonWorkshop['GravitonWorkshop']['id'])); ?> </li>
		<li><?php echo $html->link(__('List GravitonWorkshops', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New GravitonWorkshop', true), array('action'=>'add')); ?> </li>
	</ul>
</div>
