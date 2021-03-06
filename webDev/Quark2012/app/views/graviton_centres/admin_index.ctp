<div class="gravitonCentres index">
<h2><?php __('Graviton Centres');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('name');?></th>
	<th><?php echo $paginator->sort('code');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($gravitonCentres as $gravitonCentre):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $gravitonCentre['GravitonCentre']['name']; ?>
		</td>
		<td>
			<?php echo $gravitonCentre['GravitonCentre']['code']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action'=>'view', $gravitonCentre['GravitonCentre']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action'=>'edit', $gravitonCentre['GravitonCentre']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $gravitonCentre['GravitonCentre']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonCentre['GravitonCentre']['id'])); ?>
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
		<li><?php echo $html->link(__('New Graviton Centre', true), array('action'=>'add')); ?></li>
		<li><?php echo $html->link(__('List Graviton Teams', true), array('controller'=> 'graviton_teams', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Graviton Team', true), array('controller'=> 'graviton_teams', 'action'=>'add')); ?> </li>
	</ul>
</div>
