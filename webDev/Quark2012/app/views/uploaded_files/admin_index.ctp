<div class="uploadedFiles index">
<h2><?php __('Uploaded Files');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('name');?></th>
	<!--<th class="actions"><?php __('Actions');?></th>-->
</tr>
<?php
$i = 0;
foreach ($uploadedFiles as $uploadedFile):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td>
			<?php
				if ($uploadedFile['UploadedFile']['type'] == 'Picture') {
					echo '/img/uploads/';
				} else {
					echo '/files/';
				}
				echo $uploadedFile['UploadedFile']['name'];
			?>
		</td>
		<!--<td class="actions">
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $uploadedFile['UploadedFile']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $uploadedFile['UploadedFile']['id'])); ?>
		</td>-->
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
		<li><?php echo $html->link(__('Upload New File', true), array('action'=>'add')); ?></li>
	</ul>
</div>
