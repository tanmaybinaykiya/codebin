<?php
	echo $this->element('page', array(
		'name' => $categoryData['Category']['name'],
		'content' => $categoryData['Category']['content']
	));
?>
<?php foreach ($categoryData['Event'] as $event): ?>
<h2><?php echo $html->link($event['name'], '/' . $event['route']); ?></h2>
<?php echo $event['intro']; ?>
<?php endforeach; ?>