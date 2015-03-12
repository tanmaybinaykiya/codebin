<div class="workshops index">
<h2><?php __('Workshops');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('name');?></th>
	<th><?php echo $paginator->sort('price');?></th>
        <th><?php echo $paginator->sort('intro');?></th>
	<th><?php echo $paginator->sort('content');?></th>
        <th><?php echo $paginator->sort('rules');?></th>
	<th><?php echo $paginator->sort('route');?></th>
        <th><?php echo $paginator->sort('team_event');?></th>
        <th><?php echo $paginator->sort('no_of_members');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($workshops as $workshop):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $workshop['Workshop']['name']; ?>
		</td>
		<td>
			Rs. <?php echo $workshop['Workshop']['price']; ?>
		</td>
                <td>
			<?php echo $parser->getStripPreview($workshop['Workshop']['introduction'], 25); ?>
		</td>
		<td>
			<?php echo $parser->getStripPreview($workshop['Workshop']['content'], 25); ?>
		</td>
                <td>
			<?php echo $parser->getStripPreview($workshop['Workshop']['rules'], 25); ?>
		</td>
		<td>
			<?php echo $workshop['Workshop']['route']; ?>
		</td>
                <td>
			<?php echo $workshop['Workshop']['team_event']; ?>
		</td>
                <td>
			<?php echo $workshop['Workshop']['no_of_members']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action' => 'view', $workshop['Workshop']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action' => 'edit', $workshop['Workshop']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action' => 'delete', $workshop['Workshop']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $workshop['Workshop']['id'])); ?>
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
		<li><?php echo $html->link(__('New Workshop', true), array('action' => 'add')); ?></li>
	</ul>
</div>
