<h1>Graviton Admin Panel</h1>
<div class="gravitonWorkshops index">
<h2><?php __('Graviton Workshops');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('name');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($gravitonWorkshops as $gravitonWorkshop):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<h3><?php echo $gravitonWorkshop['GravitonWorkshop']['name']; ?></h3>
			Minimum Members: <?php echo $gravitonWorkshop['GravitonWorkshop']['min_members']; ?> |
			Maximum Members: <?php echo $gravitonWorkshop['GravitonWorkshop']['max_members']; ?> |
			Route: <?php echo $gravitonWorkshop['GravitonWorkshop']['route']; ?><br /><br />
			<?php 
				$gravitonCentres = $gravitonWorkshop['GravitonCentre'];
				if (count($gravitonCentres) == 0):
			?>
					There are no centres available.
			<?php 
				else:				
			?>
				<table cellpadding="0" cellspacing="0">
					<tr>
						<th>Graviton Centre</th>
						<th>Centre Code</th>
						<th class="actions">Actions</th>
					</tr>
					<?php
					$j = 0;
					foreach ($gravitonCentres as $gravitonCentre):
						$class = null;
						if ($j++ % 2 == 0) {
							$class = ' class="altrow"';
						}
					?>
						<tr<?php echo $class;?>>
							<td>
								<?php echo $gravitonCentre['name']; ?>
							</td>
							<td>
								<?php echo $gravitonCentre['code']; ?>
							</td>
							<td class="actions">
								<?php echo $html->link(__('Details', true), array('action'=>'view_centre', $gravitonCentre['id'])); ?>
								<?php echo $html->link(__('Feedback', true), array('action'=>'feedback', $gravitonCentre['id'])); ?>
								<?php echo $html->link(__('Edit', true), array('action'=>'edit_centre', $gravitonCentre['id'])); ?>
								<?php echo $html->link(__('Delete', true), array('action'=>'delete_centre', $gravitonCentre['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonCentre['id'])); ?>
							</td>
						</tr>
					<?php endforeach; ?>
				</table>
			<?php endif; ?>
			<br /><br />
		</td>
		<td class="actions">
			<?php echo $html->link(__('Edit', true), array('action'=>'edit_workshop', $gravitonWorkshop['GravitonWorkshop']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete_workshop', $gravitonWorkshop['GravitonWorkshop']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonWorkshop['GravitonWorkshop']['id'])); ?>
		</td>
	</tr>
<?php endforeach; ?>
</table>
</div>
<div class="paging">
	<?php echo $paginator->prev('<< '.__('previous', true), array(), null, array('class'=>'disabled'));?>
 | 	<?php echo $paginator->numbers();?>
	<?php echo $paginator->next(__('next', true).' >>', array(), null, array('class'=>'disabled'));?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('New Graviton Workshop', true), array('action'=>'add_workshop')); ?></li>
		<li><?php echo $html->link(__('New Graviton Centre', true), array('action'=>'add_centre')); ?></li>
	</ul>
</div>