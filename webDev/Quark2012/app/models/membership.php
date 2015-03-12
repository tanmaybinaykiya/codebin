<?php
class Membership extends AppModel {
	var $useTable = 'teams_users';
	var $belongsTo = array('Team', 'User');
	var $recursive = -1;

        function fetchTeams($userId = null) {
            if (empty($userId)) {
                return null;
            }
            $this->query("SET SESSION SQL_BIG_SELECTS=1;");
           return $this->find('all', array(
                'conditions' => array('Membership.user_id' => $userId),
                'recursive' => 3
            ));
        }
}