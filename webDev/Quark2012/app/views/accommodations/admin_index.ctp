<div style="float: right;"><h2><?php echo $html->link('Export as CSV', '/admin/accommodations/export_csv'); ?></h2></div>
<div class="accommodations index">
<h2><?php __('Accommodations');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('user_id');?></th>
        <th><?php echo $paginator->sort('quark_ids');?></th>
	<th><?php echo $paginator->sort('time_in');?></th>
	<th><?php echo $paginator->sort('time_out');?></th>
	<th><?php echo $paginator->sort('numboys');?></th>
        <th><?php echo $paginator->sort('numgirls');?></th>
        <th><?php echo $paginator->sort('contact_no');?></th>
	<th><?php echo $paginator->sort('alternate_contact_no');?></th>
        <th><?php echo $paginator->sort('approval');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($accommodations as $accommodation):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $html->link($accommodation['User']['name'], array('controller' => 'users', 'action' => 'view', $accommodation['User']['id'])); ?>
		</td>
                <td>
			<?php echo $accommodation['Accommodation']['quark_ids']; ?>
		</td>
		<td>
			<?php echo $parser->getNiceDate($accommodation['Accommodation']['time_in']); ?>
		</td>
		<td>
			<?php echo $parser->getNiceDate($accommodation['Accommodation']['time_out']); ?>
		</td>
		<td>
			<?php echo $accommodation['Accommodation']['numboys']; ?>
		</td>
                <td>
			<?php echo $accommodation['Accommodation']['numgirls']; ?>
		</td>
		<td>
			<?php echo $accommodation['Accommodation']['contact_no']; ?>
		</td>
		<td>
			<?php echo $accommodation['Accommodation']['alternate_contact_no']; ?>
		</td>
                <td>
			<?php echo $accommodation['Accommodation']['approval']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action' => 'view', $accommodation['Accommodation']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action' => 'edit', $accommodation['Accommodation']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action' => 'delete', $accommodation['Accommodation']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $accommodation['Accommodation']['id'])); ?>
		</td>
	</tr>
<?php endforeach; ?>
</table>
</div>
<div class="paging">
	<?php echo $paginator->prev('<< '.__('previous', true), array(), null, array('class'=>'disabled'));?>
 | 	<?php echo $paginator->numbers();?>
	<?php echo $paginator->next(__('next', true).' >>', array(), null, array('class' => 'disabled'));?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('New Accommodation', true), array('action' => 'add')); ?></li>
		<li><?php echo $html->link(__('List Users', true), array('controller' => 'users', 'action' => 'index')); ?> </li>
		<li><?php echo $html->link(__('New User', true), array('controller' => 'users', 'action' => 'add')); ?> </li>
	</ul>
</div>
