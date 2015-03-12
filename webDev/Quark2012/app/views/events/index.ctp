
<?php if (isset($hasRegistered) && !$hasRegistered): ?>
    <div style="float: right;">
        <?php echo $html->link('Register for the Event', array('controller' => 'users', 'action' => 'participate', $eventData['Event']['id'])); ?>
    </div>
<?php endif; ?>
<?php
	echo $this->element('events', array(
		'name' => $eventData['Event']['name'],
		'intro' => $eventData['Event']['intro'],
                'details' => $eventData['Event']['details'],
                'rules' => $eventData['Event']['rules'],
                'judging_criteria' => $eventData['Event']['judging_criteria'],
                'additional_info' => $eventData['Event']['additional_info'],
                'contact' => $eventData['Event']['contact'],
                'min_participants' => $eventData['Event']['min_participants'],
                'max_participants' => $eventData['Event']['max_participants'],
	));
?>