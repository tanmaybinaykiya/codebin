<div class="colleges view">
<h2><?php  __('College');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $college['College']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('College'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $college['College']['college']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Edit College', true), array('action' => 'edit', $college['College']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete College', true), array('action' => 'delete', $college['College']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $college['College']['id'])); ?> </li>
		<li><?php echo $html->link(__('List Colleges', true), array('action' => 'index')); ?> </li>
		<li><?php echo $html->link(__('New College', true), array('action' => 'add')); ?> </li>
	</ul>
</div>
