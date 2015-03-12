$(document).ready(function(){
	$inviteForm = $('#team-invite');
	$('.invite').click(function(){
		// Set Event Name
		$('#team-invite-event-name').text($(this).attr("event"));
		// Set Team Id [naming convention = CakePHP]
		$('#InviteTeamId').val($(this).attr("team"));
		var auxiliary = $(this).attr("auxiliary");
		$('#team-invite .select').each(function(){
			if (auxiliary <= 0) {
				$(this).children('select').each(function(){
					$(this).val('member');
				});
				$(this).hide();
			} else {
				$(this).show();
			}
		});
		$inviteForm.show('slow');
		$.scrollTo($inviteForm, 300);
	});
});