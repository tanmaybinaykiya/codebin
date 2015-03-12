<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title><?php echo $title_for_layout; if (!empty($title_for_layout)) echo ' | '; ?>QUARK 2012 | Feb 3rd - 6th | BITS, Pilani - K.K. Birla Goa Campus</title>
<?php
	echo $html->css('register');
	echo $javascript->link('jquery-1.3.2.min');
	echo $javascript->link('jticker');

        echo $scripts_for_layout;
?>
<script type="text/javascript">
	$(document).ready(function(){
		$("#accordion").children(".category")
			.bind("mouseover", function(){
				$thisEventsMenu = $(this).next();
				$("#accordion").children(".events").not($thisEventsMenu).slideUp();
				$thisEventsMenu.slideDown();
			});
		$("#jump_to").change(function(){
			location.href = $(this).val();
		});
		//The Ticker And Subticker
		$("#ticker1").jticker({
			delay: 4000,
			newwindow: true,
			url: "<?php echo $html->url('/files/tickerdata.xml'); ?>",
			transition: "fade",
			speed: "fast"
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
 <?php echo $html->meta(
    'favicon.ico',
    'favicon.ico',
    array('type' => 'icon')
);?>
</head>
<body>
<div id="container">
	<center>
	<div id="wrapper">
		<div id="banner">
			<?php echo $html->image('1.png', array('url' => '/')); ?>
		</div>
		<div id="header">
			<ul class="navbar">
				<li><span class="middle"><?php echo $html->link('home', '../../index.html'); ?></span></li>
				<!--<li><span class="middle"><?php echo $html->link('forum', '/forum'); ?></span></li>-->
				<li><span class="middle"><?php echo $html->link('participation', '/participation'); ?></span></li>
				<li><span class="middle"><?php echo $html->link('sponsors', '/sponsors'); ?></span></li>
				<li><span class="middle"><?php echo $html->link('contact us', '/contact_us'); ?></span></li>
                                <li><span class="middle"><?php echo $html->link('accommodation', '/hospitality'); ?></span></li>
                                <?php if (!$session->check('Auth.User')): ?>
				<li><span class="middle"><?php echo $html->link('login', '/users/login'); ?></span></li>
				<li><span><?php echo $html->link('register', '/users/register'); ?></span></li>
                                <?php else: ?>
                                <li><span class="middle"><?php echo $html->link('profile', '/users'); ?></span></li>
				<li><span><?php echo $html->link('logout', '/users/logout'); ?></span></li>
                                <?php endif; ?>
			</ul>
			<div id="updates">
				<div id="ticker1"></div>
			</div>
		</div>
		<div class="clear"></div>
		<div id="content">
			<div id="content_top">
				<ul id="main_navbar" class="navbar">
					<li><span class="wide middle"><?php echo $html->link('events', '/events'); ?></span></li>
                                        <li><span class="wide middle"><?php echo $html->link('online events', '/online_events'); ?></span></li>
                                        <li><span class="wide middle"><?php echo $html->link('initiatives', '/initiatives'); ?></span></li>
					<li><span class="wide middle"><?php echo $html->link('aurora', '/aurora'); ?></span></li>
					<li><span class="wide middle"><?php echo $html->link('exhibitions', '/exhibitions'); ?></span></li>
					<li><span class="wide middle"><?php echo $html->link('workshops', '/workshops'); ?></span></li>
					<li><span class="wide middle"><?php echo $html->link('lectures', '/guest_lectures'); ?></span></li>
					<li><span class="wide middle"><?php echo $html->link('bitsmun', 'http://www.bitsmun.in', array('target'=>'_blank')); ?></span></li>
					<li><span class="wide"><?php echo $html->link('schedule', '/files/schedule.jpg'); ?></span></li>
				</ul>
				<div id="columns">
					<span class="column1" style="color:#787878;">

                                            <center>
                                           <?php if(isset($if)):?>

                                                <div id="8" class="eventsinfotab"><a href="javascript:void(0);">Introduction</a></div> |


                                                <div id="9" class="eventsinfotab"><a href="javascript:void(0);">Details</a></div> |


                                                <div id="10" class="eventsinfotab"><a href="javascript:void(0);">Rules</a></div> |

                                                <?php if($eventData['Event']['judging_criteria']!=""): ?>
                                                <div id="11" class="eventsinfotab"><a href="javascript:void(0);">Judging Criteria</a></div> |
                                                <?php endif;?>
                                                <?php if($eventData['Event']['additional_info']!=""): ?>
                                                <div id="12" class="eventsinfotab"><a href="javascript:void(0);">Resources</a></div> |
                                                <?php endif;?>


                                                <div id="14" class="eventsinfotab"><a href="javascript:void(0);">Contacts</a></div>

                                            <?php endif; ?>
                                            </center>
					</span>
					<!--<span class="column2">
						<span id="events">Events | Quick Navigation</span>
					</span>
					<span class="column3">
						<span id="featured_links">featured links</span>
					</span>-->
				</div>
			</div>
			<div id="content_body">
				<span class="column1" style="width:875px">
					<?php if ($session->check('Message.flash')): ?>
					    <?php $session->flash(); ?>
					<?php endif; ?>
					<?php echo $content_for_layout; ?>
				</span>
				<!--<span class="column2">
					<div id="accordion">
						<?php foreach ($categories_for_layout as $category): ?>
						<div class="category"><?php echo $html->link($category['Category']['name'], '/' . $category['Category']['route']); ?></div>
						<ul class="events">
							<?php foreach ($category['Event'] as $event): ?>
							<li><?php echo $html->link($event['name'], '/' . $event['route']); ?></li>
							<?php endforeach; ?>
						</ul>
						<?php endforeach; ?>
					</div>
				</span>-->
				<!--<span class="column3" >

                                        <?php echo $html->image('feature3.jpg', array('class' => 'feature','url' => '/initiatives')); ?>
                        		<br /><br />
					<a href="http://www.tedxbitsgoa.com" target="_blank"><?php echo $html->image('feature2.png', array('class' => 'feature')); ?></a>
                                        <br/><br/>
                                        <?php echo $html->image('feature1.jpg', array('class' => 'feature', 'url' => '/graviton')); ?>
				</span>-->
			</div>
			<div id="content_bottom">
				Created by: <?php
                                                echo $html->image('depp.png', array('style' => 'vertical-align:middle'));
                                                echo $html->link('Department of Publicity & Public Relations', 'http://www.bits-depp.org'); ?>
			</div>
		</div>
	</div>
	</center>
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
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-19516107-2']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</body>
</html>