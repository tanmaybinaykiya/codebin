<?php echo $html->css('form', false); ?>
<?php echo $html->css('profile', false); ?>
<?php echo $javascript->link('jquery.MultiFile');?>
<?php echo $javascript->link('jquery.highlightFade');?>
<script type="text/javascript">
	function addFormField()
	{
		var id = document.getElementById("id").value;
		$("#divTxt").append("<p id='row" + id + "'><label for='txt" + id + "'>Member " + id + "&nbsp;&nbsp;<input type='text' size='20' name='data[Accommodation][quark_ids][]' id='txt" + id + "'>&nbsp;&nbsp<a href='#' onClick='removeFormField(\"#row" + id + "\"); return false;'>Remove</a><p>");
		
		
		$('#row' + id).highlightFade({
			speed:1000
		});
		
		id = (id - 1) + 2;
		document.getElementById("id").value = id;
	}
	
	function removeFormField(id)
	{
		$(id).remove();
	}
</script>
<h2>Accommodation Registration</h2>
<?php if (!empty($accommodation)): ?>
    <p><strong>Your Current Details:</strong></p>
    <?php echo $this->element('accommodation_details', array('accommodation' => $accommodation,'uploadedfiles' => $uploadedfiles)); ?>
    <p><strong>To make any changes, re-fill the form below:</strong></p>
<?php endif; ?>
<?php
    echo $form->create('Accommodation', array('class' => 'form', 'url' => '/users/accommodation','type'=>'file'));
    ?><p><a href="#" onClick="addFormField(); return false;">Add quark id</a></p>
    <input type="hidden" id="id" value="1">
	<div id="divTxt"></div>
<?php
    echo $form->input('numboys',array('label' => 'Number of boys'));
    echo $form->input('numgirls',array('label' => 'Number of girls'));
    echo $form->input('time_in', array('dateFormat' => 'MDY', 'interval' => '15', 'minDay' => '2', 'maxDay' => '7', 'minMonth' => '2', 'maxMonth' => '2', 'minYear' => '2012', 'maxYear' => '2012'));
    echo $form->input('time_out', array('dateFormat' => 'MDY', 'interval' => '15', 'minDay' => '2', 'maxDay' => '7', 'minMonth' => '2', 'maxMonth' => '2', 'minYear' => '2012', 'maxYear' => '2012'));
    
    echo $form->input('contact_no',array('maxlength' => '10', 'between' => '+91'));
    echo $form->input('alternate_contact_no', array('maxlength' => '10', 'between' => '+91'));
    ?><br/><?php
    echo $form->label('travel_proof');
    echo $form->file('Accommodation.travelproof', array('class' => "multi max-1 accept-rar|7z|zip|zipx" , 'name' => 'data[Accommodation][travelproof][]'));
    echo $form->end('Submit');
?>
<br clear="all"/>
<div style="float:right"><?php echo $html->link('Return to profile', '/users'); ?></div>