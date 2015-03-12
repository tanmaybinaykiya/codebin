<?php echo $html->css('profile', false); ?>
<?php echo $html->css('form', false); ?>
<?php echo $javascript->link('teamInvite', false); ?>
<h1>Members' Area</h1>
<div class="section">
	<div class="section-title">Your Profile</div>
	<div class="section-body">
		<div class="section-label">Quark ID</div>
		<div class="section-detail">Q11<?php echo $user['User']['id_no']; ?></div>
		<br clear="all" />
		<div class="section-label">Name</div>
		<div class="section-detail"><?php echo $user['User']['name']; ?></div>
		<br clear="all" />
                <div class="section-label">Gender</div>
		<div class="section-detail"><?php echo $user['User']['gender']; ?></div>
		<br clear="all" />
		<div class="section-label">Email</div>
		<div class="section-detail"><?php echo $user['User']['email']; ?></div>
		<br clear="all" />
		<div class="section-label">College</div>
		<div class="section-detail"><?php if(($user['User']['college']) != NULL) echo $user['User']['college'];
                else echo $user['User']['othercollege'];?></div>
		<br clear="all" />
		<div class="section-label">Mobile</div>
		<div class="section-detail"><?php echo $user['User']['mobile']; ?></div>
                <br clear="all" />
                <div class="section-label">State</div>
		<div class="section-detail"><?php echo $user['User']['state']; ?></div>
		<br clear="all" />
                <div class="section-label">Address</div>
		<div class="section-detail"><?php echo $user['User']['address']; ?></div>
		<br clear="all" />
                <div class="section-label">Year</div>
		<div class="section-detail"><?php echo $user['User']['year']; ?></div>
		<br clear="all" />
                <p>If you wish to make changes to the above, <?php echo $html->link('click here', '/users/edit_user_info'); ?>.</p>
	</div>
</div>

<div class="section">
    <div class="section-title">Accommodation</div>
    <div class="section-body">
    <?php if (empty($accommodation)): ?>
        <p>If you would like to register for accommodation, please <?php echo $html->link('click here', '/users/accommodation'); ?>.</p>
    <?php else: ?>
        <p>You have already registered for accommodation with the following details:</p>
        <?php echo $this->element('accommodation_details', array('accommodation' => $accommodation)); ?>
        <p>If you wish to make changes to the above booking, <?php echo $html->link('click here', '/users/accommodation'); ?>.</p>
    <?php endif; ?>
    </div>
</div>
<?php if (count($teamInvites) != 0): ?>
<div class="section">
	<div class="section-title">Teams That Have Invited You</div>
	<div class="section-body">
		<?php foreach ($teamInvites as $teamInvite): ?>
				<div class="invited-event"><?php echo $html->link($teamInvite['Team']['Event']['name'], '/' . $teamInvite['Team']['Event']['route']); ?></div>
				<div class="invited-role">
					Invited as: Team Member<!--<?php echo $parser->userRole($teamInvite['Invite']['user_role']); ?>--> | Actions: <?php echo $html->link('join team', array('controller' => 'users', 'action' => 'join', $teamInvite['Invite']['team_id'])); ?>
				</div>
				<div class="team-details">
					Team Members:<br />
					<?php $teamMembers = $teamInvite['Team']['Membership']; ?>
					<ol>
						<?php foreach ($teamMembers as $teamMember): ?>
						<li>
							<?php echo $teamMember['User']['name'] ?> - <?php echo $parser->userRole($teamMember['user_role']); ?><br />
							<?php echo $teamMember['User']['email']; ?>
						</li>
						<?php endforeach; ?>
					</ol>
				</div>
		<?php endforeach; ?>
	</div>
</div>
<?php endif; ?>
<?php $inviteFlag = false; // true = Indicates that the Invite action was added ?>
<div class="section">
	<div class="section-title">Events You've Registered For</div>
	<div class="section-body">
		<?php if (count($membershipArray) == 0): ?>
			<p>You haven't registered for any event yet.</p>
		<?php endif; ?>
		<?php $i = 0; ?>
		<?php foreach ($membershipArray as $membership): ?>
			<?php
				// Set up variables
				$currentUserMembership = $membership['Membership'];
				$team = $membership['Team'];
				$event = $team['Event'];
				$members = $team['Membership'];
				// Set up available actions
				// TODO: Set up ACL
				$userActions = array();
				switch ($currentUserMembership['user_role']) {
					case 'creator':
						if ($event['max_participants'] > count($members)) {
							array_push($userActions, $html->link('invite member', 'javascript:void(0);', array('class' => 'invite', 'event' => $event['name'], 'team' => $team['id'])));
							$inviteFlag = true;
						}
						array_push($userActions, $html->link('disband team', array('controller' => 'users', 'action' => 'disband', $team['id'])));
						break;
					default:
						array_push($userActions, $html->link('quit team', array('controller' => 'users', 'action' => 'quit', $team['id'])));
				}
			?>
			<div class="registered-event"><?php echo $html->link($event['name'], '/' . $event['route']); ?></div>
			<div class="registered-event-actions">
                                Team ID: <?php echo $team['id_no']; ?><br />
				Role: <?php echo $parser->userRole($currentUserMembership['user_role']); ?> |&nbsp;
				Actions: <?php echo implode(' - ', $userActions); ?>
			</div>
			<div class="team-details">
				Team Members:<br />
				<ol>
					<?php foreach ($members as $member): ?>
						<li><?php echo $member['User']['name']; ?> - <?php echo $parser->userRole($member['user_role']); ?><br /><?php echo $member['User']['email']; ?></li>
					<?php endforeach; ?>
				</ol>
			</div>
			<?php $i++; ?>
		<?php endforeach; ?>
	</div>
</div>
<?php if ($inviteFlag): ?>
<?php echo $javascript->link('teamInvite', false); ?>
<div id="team-invite" class="section">
	<div class="section-title">Invite to Team: <strong><span id="team-invite-event-name"></span></strong></div>
	<div class="section-body">
		<div class="form">
			<?php echo $form->create('Invite', array('url' => '/users')); ?>
			<?php echo $form->input('email'); ?>
			<?php echo $form->hidden('team_id'); ?>
			<?php echo $form->submit('Invite'); ?>
		</div>
		<br clear="all" />
	</div>
</div>
<?php endif; ?>

<div class="section">
	<div class="section-title">Workshops You've Registered For</div>
	<div class="section-body">
        <?php if (empty($workshopRegistrations)): ?>
            <p>You haven't registered for any workshops yet.</p>
        <?php else: ?>
            <ul>
            <?php foreach($workshopRegistrations as $workshopRegistration): ?>
                <li>
                        <?php echo $workshopRegistration['Workshop']['name']; ?>
                </li>
            <?php endforeach; ?>
            </ul>
        <?php endif; ?>
        <p><?php echo $html->link('Click here', '/workshops'); ?> to view the workshops at Quark 2012.</p>
    </div>
</div>
