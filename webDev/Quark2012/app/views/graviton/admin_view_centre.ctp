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
		<li><?php echo $html->link(__('Edit Graviton Centre', true), array('action'=>'edit_centre', $gravitonCentre['GravitonCentre']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete Graviton Centre', true), array('action'=>'delete_centre', $gravitonCentre['GravitonCentre']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonCentre['GravitonCentre']['id'])); ?> </li>
		<li><?php echo $html->link(__('List Graviton Workshops', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Centre', true), array('action'=>'add_centre')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Team', true), array('action'=>'add_team')); ?> </li>
	</ul>
</div>
<div class="related">
	<h3><?php __('Related Graviton Teams');?></h3>
	<?php if (!empty($gravitonCentre['GravitonTeam'])):?>
	<table cellpadding = "0" cellspacing = "0">
	<tr>
		<th><?php  __('name'); ?></th>
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
		<td>
			<h4><?php echo $gravitonTeam['name']; ?></h4>
			Number: <?php echo $gravitonTeam['number']; ?> |
			Paid: <?php echo Inflector::humanize($gravitonTeam['paid']); ?>
			<br/><br/>
			<?php 
				$gravitonUsers = $gravitonTeam['GravitonUser'];
				if (count($gravitonUsers) == 0):
			?>
					There are no users available.
			<?php 
				else:				
			?>
				<table cellpadding="0" cellspacing="0">
					<tr>
						<th>Name</th>
						<th>Number</th>
						<th>Attended</th>
						<th class="actions">Actions</th>
					</tr>
					<?php
					$j = 0;
					foreach ($gravitonUsers as $gravitonUser):
						$class = null;
						if ($j++ % 2 == 0) {
							$class = ' class="altrow"';
						}
					?>
					<tr<?php echo $class;?>>
							<td>
								<?php echo $gravitonUser['name']; ?>
							</td>
							<td>
								<?php echo $gravitonUser['number']; ?>
							</td>
							<td>
								<?php echo $gravitonUser['attended']; ?>
							</td>
							<td class="actions">
								<?php echo $html->link(__('View', true), array('action'=>'view_user', $gravitonUser['id'])); ?>
								<?php echo $html->link(__('Edit', true), array('action'=>'edit_user', $gravitonUser['id'])); ?>
								<?php echo $html->link(__('Delete', true), array('action'=>'delete_user', $gravitonUser['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonCentre['GravitonCentre']['id'])); ?>
							</td>
							</tr>
					<?php endforeach; ?>
				</table>
			<?php endif; ?>
			<br /><br />
		</td>
			<td class="actions">
				<?php echo $html->link(__('Edit', true), array('action'=>'edit_team', $gravitonTeam['id'])); ?>
				<?php echo $html->link(__('Delete', true), array('action'=>'delete_team', $gravitonTeam['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonTeam['id'])); ?>
			</td>
		</tr>
	<?php endforeach; ?>
	</table>
<?php endif; ?>

	<div class="actions">
		<ul>
			<li><?php echo $html->link(__('New Graviton Team', true), array('action'=>'add_team'));?> </li>
			<li><?php echo $html->link(__('New Graviton User', true), array('action'=>'add_user'));?> </li>
		</ul>
	</div>
</div>
