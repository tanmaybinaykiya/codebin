<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title><?php echo $title_for_layout; if (!empty($title_for_layout)) echo ' | '; ?>QUARK 2012 | Innovation Festival | Feb 3rd - 6th | BITS, Pilani - Goa Campus</title>
<?php echo $html->css('cake.generic'); ?>
<?php echo $html->css('default'); ?>
<script language="javascript">AC_FL_RunContent = 0;</script>
<?php echo $javascript->link('AC_RunActiveContent'); ?>
</head>
<body>
<center>
<div id="fixed-width-wrapper">
	<!-- Website Header Starts -->
	<div id="banner">
		<!--url's used in the movie-->
		<!--text used in the movie-->
		<!-- saved from url=(0013)about:internet -->
		<script language="javascript">
			if (AC_FL_RunContent == 0) {
				alert("This page requires AC_RunActiveContent.js.");
			} else {
				AC_FL_RunContent(
					'codebase', 'http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0',
					'width', '990',
					'height', '200',
					'src', '<?php echo $html->url('/swf/quark'); ?>',
					'quality', 'high',
					'pluginspage', 'http://www.macromedia.com/go/getflashplayer',
					'align', 'middle',
					'play', 'true',
					'loop', 'true',
					'scale', 'showall',
					'wmode', 'window',
					'devicefont', 'false',
					'id', 'quark',
					'bgcolor', '#000000',
					'name', 'quark',
					'menu', 'true',
					'allowFullScreen', 'false',
					'allowScriptAccess','sameDomain',
					'movie', '<?php echo $html->url('/swf/quark'); ?>',
					'salign', ''
					); //end AC code
			}
		</script>
		<noscript>
			<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0" width="990" height="200" id="quark" align="middle">
			<param name="allowScriptAccess" value="sameDomain" />
			<param name="allowFullScreen" value="false" />
			<param name="movie" value="<?php echo $html->url('/swf/quark.swf'); ?>" /><param name="quality" value="high" /><param name="bgcolor" value="#000000" />	<embed src="<?php echo $html->url('/swf/quark.swf'); ?>" quality="high" bgcolor="#000000" width="990" height="200" name="quark" align="middle" allowScriptAccess="sameDomain" allowFullScreen="false" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />
			</object>
		</noscript>
	</div>
	<!-- Website Header Ends -->
	<!-- Website Body Begins -->
	<div id="content">
		<p><?php echo $html->image('featured.png'); ?></p>
		<p id="featured"><?php echo $html->image('featured_graviton.png', array('class' => 'featured', 'url' => '/graviton')); ?></p>
		<br />
		<p><?php echo $html->image('content.png'); ?></p>
		<?php if ($session->check('Message.flash')): ?>
		    <?php $session->flash(); ?>
		<?php endif; ?>
		<?php echo $content_for_layout; ?>
	</div>
	<div id="navbar">
		<p><?php echo $html->image('navigation.png'); ?></p>
		<p><?php echo $html->image('navbar_events.png'); ?></p>
		<p class="navbar-link-list">
			<?php echo $html->link('Chemicon', '/chemicon'); ?><br />
			<?php echo $html->link('Corporate', '/corporate'); ?><br />
			<?php echo $html->link('Electryst', '/electryst'); ?><br />
			<?php echo $html->link('Elixir', '/elixir'); ?><br />
			<?php echo $html->link('Mechagi', '/mechagi'); ?><br />
			<?php echo $html->link('Programmers Inc.', '/programmers_inc'); ?><br />
			<?php echo $html->link('Roboficial', '/roboficial'); ?><br />
		</p>
		<p><?php echo $html->image('navbar_specials.png', array('url' => '/specials')); ?></p>
		<p><?php echo $html->image('navbar_workshops.png', array('url' => '/workshops')); ?></p>
		<p><?php echo $html->image('navbar_guest_lectures.png', array('url' => '/guest_lectures')); ?></p>
		<p><?php echo $html->image('navbar_aurora.png', array('url' => '/aurora')); ?></p>
		<p><?php echo $html->image('navbar_other_links.png'); ?></p>
		<p class="navbar-link-list">
			<?php echo $html->link('Blog', '/blog'); ?><br />
			<?php echo $html->link('Forum', '/forum'); ?><br />
			<?php echo $html->link('Lookback \'09', '/lookback'); ?><br />
			<?php echo $html->link('Sponsors', '/sponsors'); ?><br />
			<?php echo $html->link('Contact Us', '/contact_us'); ?><br />
		</p>
	</div>
	<!-- Website Body Ends -->
	<div class="clear"></div>
	<br />
	<!-- Website Footer Starts -->
	<div id="footer">
		<div id="bits">
			<span id="bits-logo"><?php echo $html->image('bits-logo.jpg', array('valign' => 'middle')); ?></span>
			<span id="bits-link"><?php echo $html->link('Birla Institute of Technology and Science - Pilani<br />Goa Campus', 'http://www.bits-goa.ac.in', array(), null, false); ?></span>
		</div>
		<div id="depp">
			<span id="depp-link"><?php echo $html->link('Department of Publicity &amp;<br />Public Relations', 'http://depp.bits-quark.org', array(), null, false); ?></span>
			<span id="depp-logo"><?php echo $html->image('depp-logo.jpg', array('valign' => 'middle')); ?></span>
		</div>
		<br /><br />&nbsp;
	</div>
	<!-- Website Footer Ends -->
</div>
</center>
<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("UA-6320537-1");
pageTracker._trackPageview();
} catch(err) {}</script>
</body>
</html>