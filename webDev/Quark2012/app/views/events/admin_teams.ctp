<div class="events view">
    <h2><?php __('Export as CSV'); ?></h2>
    <p>Please take note of the following points while exporting to a CSV:</p>
    <ul>
        <li>Each password is <strong>encrypted</strong> with a salt. If you wish to use the password field for your event (such as an online event), please get in touch with the website administrator. Else, it can be ignored.</li>
        <li>You might have a problem with fields that have a comma or a quotation mark. If you do, please contact the website administrator.</li>
        <li>Please update the teams who have registered for your events whenever there's something MAJOR. Please do NOT spam them continuously.</li>
        <li>If you wish to send an SMS to all participating users, please get in touch with the website administrator to see there are any free slots for mass SMS requests.</li>
    </ul>
    <p>Finally, here it is: <?php echo $html->link('Download as CSV', '/admin/events/teams_csv/' . $eventId); ?> &nbsp;&nbsp; <?php echo $html->link('Download as CSV (Only Team Leaders)', '/admin/events/teams_csv/' . $eventId . '/tl'); ?></p>
    <h2><?php __('Registered Teams'); ?></h2>
    <ul>
        <?php foreach($teams as $team): ?>
        <li>
            Team ID: <?php echo $team['id_no']; ?><br /><br />
            <ul type='square'>
                    <?php foreach($team['Membership'] as $Membership): ?>
                <li><?php echo $Membership['User']['name']. ' (Quark ID: ' . $Membership['User']['id_no'] . ')' . "<br />Email : ".$Membership['User']['email']." , <br />College : ".$Membership['User']['college']." , <br />Mobile : ".$Membership['User']['mobile']."";?><br /><br /></li>
                    <?php endforeach; ?>
            </ul>
        </li>
        <?php endforeach; ?>
    </ul>
</div>