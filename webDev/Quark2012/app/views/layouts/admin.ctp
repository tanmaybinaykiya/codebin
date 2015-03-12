<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title><?php echo $title_for_layout; if (!empty($title_for_layout)) echo ' | '; ?>Quark 2012 | Innovation Festival | Feb 4th - 6th | BITS, Pilani - Goa Campus</title>
<?php echo $html->css('cake.generic'); ?>
<?php echo $html->css('admin'); ?>
<script language="javascript">AC_FL_RunContent = 0;</script>
<?php echo $javascript->link('AC_RunActiveContent'); ?>
<?php echo $javascript->link('ckeditor/ckeditor'); ?>
<?php echo $javascript->link('ckeditor/plugins/stylescombo/styles/default'); ?>
</head>
<body>
<center>
<div id="fixed-width-wrapper">
	<!-- Website Header Starts -->
	        <?php echo $html->image('top_banner.jpg'); ?>
	<!-- Website Header Ends -->
	<!-- Website Body Begins -->
	<?php if ($session->check('Auth.User')): ?>
	<?php
                if ($permissionsCount == 0) {
                    $navLinks = array(
                        'Home' => '/admin',
                        'Colleges' => '/admin/colleges',
                        'Categories' => '/admin/categories',
                        'Events' => '/admin/events',
                        'Pages' => '/admin/pages',
                        'Graviton' => '/admin/graviton',
                        'Accommodations' => '/admin/accommodations',
                        'Permissions' => '/admin/permissions',
                        'Uploaded Files' => '/admin/uploaded_files',
                        'Workshops' => '/admin/workshops'
                    );
                } else {
                    $navLinks = array();
                    $navLinks['Home'] = '/admin';
                    if (in_array('College', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Colleges'] = '/admin/colleges';
                    if (in_array('Category', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Categories'] = '/admin/categories';
                    if (in_array('Event', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Events'] = '/admin/events';
                    if (in_array('Page', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Pages'] = '/admin/pages';
                    if (in_array('Workshop', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Workshops'] = '/admin/workshops';
                    if (in_array('Graviton', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Graviton'] = '/admin/graviton';
                    if (in_array('Accommodation', $allowedResources) || in_array('All', $allowedResources)) $navLinks['Accommodations'] = '/admin/accommodations';
                    if (in_array('All', $allowedResources)) $navLinks['Permissions'] = '/admin/permissions';
                    $navLinks['Uploaded Files'] = '/admin/uploaded_files';
                }
	?>
	|
	<?php foreach ($navLinks as $text => $url): ?>
		<?php echo $html->link($text, $url); ?> |
	<?php endforeach; ?>
	<div id="logout">
		<?php echo $html->link('Logout', array('controller' => 'users', 'action' => 'logout', 'admin' => true)); ?>
	</div>
	<?php endif; ?>
	<div id="content">
		<?php if ($session->check('Message.flash')): ?>
		    <?php $session->flash(); ?>
		<?php endif; ?>
		<?php echo $content_for_layout; ?>
	</div>
	<!-- Website Body Ends -->
	<br /><br />
	<div class="clear"></div>
	<!-- Website Footer Starts -->
	<div id="footer">
		<div id="bits">
			<span id="bits-logo"><?php echo $html->image('bits-logo.jpg', array('valign' => 'middle')); ?></span>
			<span id="bits-link"><?php echo $html->link('Birla Institute of Technology and Science, Pilani<br />Goa Campus', 'http://www.bits-goa.ac.in', array(), null, false); ?></span>
		</div>

		<br /><br />&nbsp;
	</div>
	<!-- Website Footer Ends -->
</div>
</center>
</body>
</html>