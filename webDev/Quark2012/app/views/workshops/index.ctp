<div style="float: right;">
    <?php echo $html->link('Register for the Workshop', array('controller' => 'users', 'action' => 'workshop', $workshopData['Workshop']['id'])); ?>
</div>
<?php
	echo $this->element('workshop', array(
		'name' => $workshopData['Workshop']['name'],
                'intro' => $workshopData['Workshop']['introduction'],
		'content' => $workshopData['Workshop']['content'],
                'rules' => $workshopData['Workshop']['rules']
	));
?>