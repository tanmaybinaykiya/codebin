<div class="gravitonUsers index">
<h2><?php __('GravitonUsers');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('id');?></th>
	<th><?php echo $paginator->sort('city');?></th>
	<th><?php echo $paginator->sort('name');?></th>
	<th><?php echo $paginator->sort('college');?></th>
	<th><?php echo $paginator->sort('state');?></th>
	<th><?php echo $paginator->sort('email');?></th>
	<th><?php echo $paginator->sort('mobile');?></th>
	<th><?php echo $paginator->sort('member1_name');?></th>
	<th><?php echo $paginator->sort('member1_mobile');?></th>
	<th><?php echo $paginator->sort('member2_name');?></th>
	<th><?php echo $paginator->sort('member2_mobile');?></th>
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($gravitonUsers as $gravitonUser):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php echo $gravitonUser['GravitonUser']['id']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['city']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['name']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['college']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['state']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['email']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['mobile']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['member1_name']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['member1_mobile']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['member2_name']; ?>
		</td>
		<td>
			<?php echo $gravitonUser['GravitonUser']['member2_mobile']; ?>
		</td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action'=>'view', $gravitonUser['GravitonUser']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action'=>'edit', $gravitonUser['GravitonUser']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $gravitonUser['GravitonUser']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $gravitonUser['GravitonUser']['id'])); ?>
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
		<li><?php echo $html->link(__('New GravitonUser', true), array('action'=>'add')); ?></li>
	</ul>
</div>
