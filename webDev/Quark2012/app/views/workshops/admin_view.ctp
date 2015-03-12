<div class="workshops view">
<h2><?php  __('Workshop');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Name'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['name']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Price'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['price']; ?>
			&nbsp;
		</dd>
                <dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Introduction'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['introduction']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Content'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['content']; ?>
			&nbsp;
		</dd>
                <dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Rules'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['rules']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Route'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['route']; ?>
			&nbsp;
		</dd>
                <dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Team event'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['team_event']; ?>
			&nbsp;
		</dd>
                <dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Members'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $workshop['Workshop']['no_of_members']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Edit Workshop', true), array('action' => 'edit', $workshop['Workshop']['id'])); ?> </li>
		<li><?php echo $html->link(__('Delete Workshop', true), array('action' => 'delete', $workshop['Workshop']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $workshop['Workshop']['id'])); ?> </li>
		<li><?php echo $html->link(__('List Workshops', true), array('action' => 'index')); ?> </li>
		<li><?php echo $html->link(__('New Workshop', true), array('action' => 'add')); ?> </li>
	</ul>
</div>

<table cellpadding="0" cellspacing="0">
<tr>
    <th>No.</th>
	<th>Quark ID</th>
	<th>Name</th>
	<th>Mobile no.</th>
	<th>College</th>
	<th>Email</th>
        <th>Team ID</th>
</tr>
<?php
$i = 1;
foreach ($workshop['WorkshopsUser'] as $workshopsUser):
	$class = null;
	if ($i % 2 == 1) {
		$class = ' class="altrow"';
	}
?>
	<tr <?php echo $class;?>>
		<td>
			<?php echo $i; ?>
		</td>
		<td>
			<?php echo 'Q11'.$workshopsUser['User']['id_no']; ?>
		</td>
		<td>
			<?php echo $workshopsUser['User']['name']; ?>
		</td>
		<td>
			<?php echo $workshopsUser['User']['mobile']; ?>
		</td>
		<td>
			<?php echo $workshopsUser['User']['college']; ?>
		</td>
		<td>
			<?php echo $workshopsUser['User']['email']; ?>
		</td>
                <td>
			<?php echo $workshopsUser['team_id']; ?>
		</td>
	</tr>
<?php 
$i++;
endforeach; ?>
</table>