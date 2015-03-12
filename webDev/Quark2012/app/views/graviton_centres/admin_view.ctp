<div class="gravitonCentres view">
<h2><?php  __('GravitonCentre');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonCentre['GravitonCentre']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Name'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonCentre['GravitonCentre']['name']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Code'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $gravitonCentre['GravitonCentre']['code']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Edit GravitonCentre', true), array('action'=>'edit', $gravitonCentre['GravitonCentre']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete GravitonCentre', true), array('action'=>'delete', $gravitonCentre['GravitonCentre']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonCentre['GravitonCentre']['id'])); ?> </li>
		<li><?php echo $html->link(__('List GravitonCentres', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New GravitonCentre', true), array('action'=>'add')); ?> </li>
		<li><?php echo $html->link(__('List Graviton Teams', true), array('controller'=> 'graviton_teams', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Team', true), array('controller'=> 'graviton_teams', 'action'=>'add')); ?> </li>
	</ul>
</div>
<div class="related">
	<h3><?php __('Related Graviton Teams');?></h3>
	<?php if (!empty($gravitonCentre['GravitonTeam'])):?>
	<table cellpadding = "0" cellspacing = "0">
	<tr>
		<th><?php __('Id'); ?></th>
		<th><?php __('Graviton Centre Id'); ?></th>
		<th><?php __('Name'); ?></th>
		<th><?php __('Id No'); ?></th>
		<th class="actions"><?php __('Actions');?></th>
	</tr>
	<?php
		$i = 0;
		foreach ($gravitonCentre['GravitonTeam'] as $gravitonTeam):
			$class = null;
			if ($i++ % 2 == 0) {
				$class = ' class="altrow"';
			}
		?>
		<tr<?php echo $class;?>>
			<td><?php echo $gravitonTeam['id'];?></td>
			<td><?php echo $gravitonTeam['graviton_centre_id'];?></td>
			<td><?php echo $gravitonTeam['name'];?></td>
			<td><?php echo $gravitonTeam['id_no'];?></td>
			<td class="actions">
				<?php echo $html->link(__('View', true), array('controller'=> 'graviton_teams', 'action'=>'view', $gravitonTeam['id'])); ?>
				<?php echo $html->link(__('Edit', true), array('controller'=> 'graviton_teams', 'action'=>'edit', $gravitonTeam['id'])); ?>
				<?php echo $html->link(__('Delete', true), array('controller'=> 'graviton_teams', 'action'=>'delete', $gravitonTeam['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonTeam['id'])); ?>
			</td>
		</tr>
	<?php endforeach; ?>
	</table>
<?php endif; ?>

	<div class="actions">
		<ul>
			<li><?php echo $html->link(__('New Graviton Team', true), array('controller'=> 'graviton_teams', 'action'=>'add'));?> </li>
		</ul>
	</div>
</div>
