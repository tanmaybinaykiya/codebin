<div class="gravitonTeams view">
<h2><?php  __('GravitonTeam');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonTeam['GravitonTeam']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Graviton Centre Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonTeam['GravitonTeam']['graviton_centre_id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Name'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonTeam['GravitonTeam']['name']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Number'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonTeam['GravitonTeam']['number']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Edit GravitonTeam', true), array('action'=>'edit', $gravitonTeam['GravitonTeam']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete GravitonTeam', true), array('action'=>'delete', $gravitonTeam['GravitonTeam']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonTeam['GravitonTeam']['id'])); ?> </li>
		<li><?php echo $html->link(__('List GravitonTeams', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New GravitonTeam', true), array('action'=>'add')); ?> </li>
	</ul>
</div>
