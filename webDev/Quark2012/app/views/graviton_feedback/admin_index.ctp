<div class="gravitonFeedback index">
<h2><?php __('GravitonFeedback');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('id');?></th>
	<th><?php echo $paginator->sort('name');?></th>
	<th><?php echo $paginator->sort('email');?></th>
	<th><?php echo $paginator->sort('phone');?></th>
	<th><?php echo $paginator->sort('college');?></th>
	<th><?php echo $paginator->sort('graviton_workshop_id');?></th>
	<th><?php echo $paginator->sort('graviton_centre_id');?></th>
	<th><?php echo $paginator->sort('answer1');?></th>
	<th><?php echo $paginator->sort('answer2');?></th>
	<th><?php echo $paginator->sort('answer3');?></th>
	<th><?php echo $paginator->sort('answer4');?></th>
	<th><?php echo $paginator->sort('answer5');?></th>
	<th><?php echo $paginator->sort('answer6');?></th>
	<th><?php echo $paginator->sort('no_of_kits');?></th>
	<th><?php echo $paginator->sort('comments');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($gravitonFeedback as $gravitonFeedback):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['id']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['name']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['email']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['phone']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['college']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['graviton_workshop_id']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['graviton_centre_id']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer1']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer2']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer3']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer4']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer5']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['answer6']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['no_of_kits']; ?>
		</td>
		<td>
			<?php echo $gravitonFeedback['GravitonFeedback']['comments']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action'=>'view', $gravitonFeedback['GravitonFeedback']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action'=>'edit', $gravitonFeedback['GravitonFeedback']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $gravitonFeedback['GravitonFeedback']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonFeedback['GravitonFeedback']['id'])); ?>
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
		<li><?php echo $html->link(__('New GravitonFeedback', true), array('action'=>'add')); ?></li>
	</ul>
</div>
