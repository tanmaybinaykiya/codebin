<?php
class Invite extends AppModel {
    var $belongsTo = array('Team');
    var $validate = array(
        'email' => array(
            'notEmpty' => array(
                'rule' => 'notEmpty',
                'message' => 'Please enter an e-mail address.',
                'required' => true
            ),
            'email' => array(
                'rule' => 'email',
                'message' => 'Please enter a valid e-mail address.'
            )
        )
    );

    function fetchByEmail($email = null) {
        if ($email != null) {
            $this->Team->unbindModel(array('hasMany' => array('Invite')));
            $this->Team->Membership->unbindModel(array('belongsTo' => array('Team')));
            return $this->find('all', array(
                'conditions' => array('Invite.email' => $email),
                'recursive' => 3
            ));
        }
        return null;
    }
}