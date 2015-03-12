<?php
	echo $this->element('page', array(
		'name' => $pageData['Page']['name'],
		'content' => $pageData['Page']['content']
	));
?>
<?php foreach ($categories as $category): ?>
	<h2><a href="<?php echo $category['Category']['route']; ?>"><?php echo $category['Category']['name']; ?></a></h2>
	<?php echo $category['Category']['content']; ?>
<?php endforeach; ?>