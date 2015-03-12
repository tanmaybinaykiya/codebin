<?php
class GravitonTeam extends AppModel {

	var $name = 'GravitonTeam';

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'GravitonCentre' => array(
			'className' => 'GravitonCentre',
			'foreignKey' => 'graviton_centre_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);

	var $hasMany = array(
		'GravitonUser' => array(
			'className' => 'GravitonUser',
			'foreignKey' => 'graviton_team_id',
			'dependent' => false,
			'conditions' => '',
			'fields' => '',
			'order' => '',
			'limit' => '',
			'offset' => '',
			'exclusive' => '',
			'finderQuery' => '',
			'counterQuery' => ''
		)
	);

	function newTeamNumber($gravitonCentreId = null) {
		if (!empty($gravitonCentreId)) {
			$maxTeamId = $this->field('MAX(GravitonTeam.number)', array('GravitonTeam.graviton_centre_id' => $gravitonCentreId));
			if (empty($maxTeamId)) {
				return 1;
			} else {
				return $maxTeamId + 1;
			}
		}
		return null;
	}

	function generateTeamId($number, $gravitonCentreId) {
		$gravitonCentreCode = $this->GravitonCentre->field('GravitonCentre.code', array('GravitonCentre.id' => $gravitonCentreId));
		return $gravitonCentreCode . str_pad($number, 3, "0", STR_PAD_LEFT);
	}

}
?>