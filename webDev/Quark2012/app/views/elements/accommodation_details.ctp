<div class="section-label">Your accomodation Team ID</div>
<div class="section-detail"><?php echo 'A'.$session->read('Auth.User.id_no'); ?></div>
<br clear="all" />
<div class="section-label">Quark IDs</div>
<?php 	$quark_ids = array();
		$quark_ids = json_decode($accommodation['Accommodation']['quark_ids']);
                if(isset($quark_ids)){
		foreach($quark_ids as $id)
		{
?>
<div class="section-detail"><?php echo $id; ?></div>
<br clear="all" />
<?php } }?>
<br clear="all" />
<div class="section-label">Number of Boys</div>
<div class="section-detail"><?php echo $accommodation['Accommodation']['numboys']; ?></div>
<br clear="all" />
<div class="section-label">Number of Girls</div>
<div class="section-detail"><?php echo $accommodation['Accommodation']['numgirls']; ?></div>
<br clear="all" />
<div class="section-label">Time In</div>
<div class="section-detail"><?php echo $parser->getNiceDate($accommodation['Accommodation']['time_in']); ?></div>
<br clear="all" />
<div class="section-label">Time Out</div>
<div class="section-detail"><?php echo $parser->getNiceDate($accommodation['Accommodation']['time_out']); ?></div>
<br clear="all" />
<div class="section-label">Contact No</div>
<div class="section-detail"><?php echo $accommodation['Accommodation']['contact_no']; ?></div>
<br clear="all" />
<div class="section-label">Alternate Contact No</div>
<div class="section-detail"><?php echo $accommodation['Accommodation']['alternate_contact_no']; ?></div>
<br clear="all" />
<div class="section-label">Uploaded files</div>
<?php foreach($uploadedfiles as $file) {?>
<div class="section-detail"><?php echo $file; ?></div>
<br clear="all" />
<?php }?>
<br clear="all" />
<div class="section-label">Approval</div>
<div class="section-detail"><?php echo $accommodation['Accommodation']['approval']; ?></div>
<br clear="all" />

<br clear="all" />
