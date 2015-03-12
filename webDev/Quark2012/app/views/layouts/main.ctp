<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $title_for_layout; if (!empty($title_for_layout)) echo ' | '; ?>QUARK 2012 | Feb 3rd - 6th | BITS, Pilani - K.K. Birla Goa Campus</title>
<?php
	echo $html->css('main');
    echo $javascript->link('jquery-1.7.min');
    echo $scripts_for_layout;
?>
<script type="text/javascript">
$(document).ready(function(){
    $("#jump_to").change(function(){
        location.href = $(this).val();
    });
	$("ul.subnav").parent().append("<span></span>"); //Only shows drop down trigger when js is enabled (Adds empty span tag after ul.subnav*)

	$("ul.bottomnav li span").hover(function() { //When trigger is clicked...

		//Following events are applied to the subnav itself (moving subnav up and down)
		$(this).parent().find("ul.subnav").slideDown('fast').show(); //Drop down the subnav on click

		$(this).parent().hover(function() {
		}, function(){
			$(this).parent().find("ul.subnav").slideUp('slow'); //When the mouse hovers out of the subnav, move it back up
		});

		//Following events are applied to the trigger (Hover events for the trigger)
		}).hover(function() {
			$(this).addClass("subhover"); //On hover over, add class "subhover"
		}, function(){	//On Hover Out
			$(this).removeClass("subhover"); //On hover out, remove class "subhover"
	});

    for(i=1;i<=7;i++)
    {

        $("#"+i).css("display","none");
    }
    $("#1").css("display","block");
    $(".eventsinfotab").click(function(){
        a=$(this).attr("id");
        for(i=1;i<=7;i++)
            {

                $("#"+i).css("display","none");
            }
        $("#"+(a-7)).css("display","block");

    });

});

</script>

</head>
<body>
	<div id="container">
		<div class="quark-logo"></div>
		<?php echo $html->image('logo-quark.png', array('url' => '/','id' => 'ab')); ?>
		<div class="updates"></div>
		<div class="fokatnavbar">
			<div class="hider"><?php echo $html->image('hider.jpg'); ?></div>
			<ul class="fokatnav" style="padding-top:5px">
                <li><?php echo $html->link('Accommodation', '/hospitality'); ?></li>
                <?php if (!$session->check('Auth.User')): ?>
				<li><?php echo $html->link('Login', '/users/login'); ?></li> | 
				<li><?php echo $html->link('Register', '/users/register'); ?></li>
                <?php else: ?>
                <li><?php echo $html->link('Profile', '/users'); ?></li>
				<li><?php echo $html->link('Logout', '/users/logout'); ?></li>
                <?php endif; ?>
			</ul>
		</div>
		<div class="navbar">
            <ul class="topnav" style="padding-top:5px;">
				<li><?php echo $html->link('Home', '/home'); ?></li>
				<li><?php echo $html->link('Sponsors', '/sponsors'); ?></li>
				<li><?php echo $html->link('Contact us', '/contact_us'); ?></li>
                <li><?php echo $html->link('Events', '/events', array('id'=>'events')); ?></li>
                <li><?php echo $html->link('Online events', '/online_events'); ?></li>
                <li><?php echo $html->link('GCon', '/initiatives'); ?></li>
                <li><?php echo $html->link('Aurora', '/aurora'); ?></li>
                <li><?php echo $html->link('Exhibitions', '/exhibitions'); ?></li>
                <li><?php echo $html->link('Workshops', '/workshops'); ?></li>
                <li><?php echo $html->link('Lectures', '/guest_lectures'); ?></li>
                <li><?php echo $html->link('Bitsmun', 'http://www.bitsmun.in', array('target'=>'_blank')); ?></li>
                <li><?php echo $html->link('Schedule', '/files/schedule.jpg'); ?></li>
			</ul>
            <div class="clear"></div>
		</div>
		<div class="bottomnavbar">
            <ul class="bottomnav" id="eventsmenu">
                <?php foreach ($categories_for_layout as $category): ?>
                <li><?php echo $html->link($category['Category']['name'], '/' . $category['Category']['route']); ?>
                    <ul class="subnav">
                        <?php foreach ($category['Event'] as $event): ?>
                        <li><?php echo $html->link($event['name'], '/' . $event['route']); ?></li>
                        <?php endforeach; ?>
                    </ul>
                </li>

                <?php endforeach; ?>
            </ul>
        </div>
        <div class="main">
            <!--<div class="sidebar"></div>-->
            <div class="column1">
                <div class="innercolumn1">
                    <center>
                   <?php if(isset($if)):?>

                        <div id="8" class="eventsinfotab">Introduction</div>


                        <div id="9" class="eventsinfotab">Details</div>


                        <div id="10" class="eventsinfotab">Rules</div>

                        <?php if($eventData['Event']['judging_criteria']!=""): ?>
                        <div id="11" class="eventsinfotab">Judging Criteria</div>
                        <?php endif;?>
                        <?php if($eventData['Event']['additional_info']!=""): ?>
                        <div id="12" class="eventsinfotab">Resources</div>
                        <?php endif;?>


                        <div id="14" class="eventsinfotab">Contacts</div>

                    <?php endif; ?>
					<?php if(!isset($if)):?>
					<div>Quark - 2012<br />Challenge.<br />Compete.<br />Evolve</div>
					<?php endif; ?>
                    <?php if(isset($ifworkshop)):?>

                        <div id="8" class="eventsinfotab">Introduction</div>


                        <div id="9" class="eventsinfotab">Course Content</div>


                        <div id="10" class="eventsinfotab">Rules</div>
                    <?php endif; ?>
                    </center>
                </div>
			</div>
            <div class="column2">
                <div id="content"><?php echo $content_for_layout; ?></div>
            </div>
        </div>
    </div>
    <div id="footer">
        <center>
        <span id="footer_wrapper">
            <span id="bits_link">
                <?php echo $html->image('bits_logo.png', array('id' => 'bits_logo')); ?>&nbsp;<?php echo $html->link('Birla Institute of Technology And Science, Pilani | K.K. Birla Goa Campus', 'http://www.bits-goa.ac.in'); ?>
            </span>
            <span id="jump">
                <?php
                    $jumpOptions = array();
                    foreach ($categories_for_layout as $category) {
                        $jumpOptions[$category['Category']['route']] = $category['Category']['name'];
                        foreach ($category['Event'] as $event) {
                            $jumpOptions[$event['route']] = '-- ' . $event['name'];
                        }
                    }
                ?>
                Jump to:&nbsp;&nbsp;<?php echo $form->select('jump_to', $jumpOptions, array('size' => 100)); ?>
            </span>
        </span>
        </center>
    </div>
</body>
</html>