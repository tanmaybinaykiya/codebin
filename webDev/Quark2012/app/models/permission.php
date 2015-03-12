<?php
class Permission extends AppModel {

	var $name = 'Permission';
	var $validate = array(
		'user_id' => array('notempty'),
		'resource' => array('notempty')
	);

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'User' => array(
			'className' => 'User',
			'foreignKey' => 'user_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);

        // returns denied / view_edit / add_delete
        function check($userId, $resource, $resourceId = null) {
            // Invalid specification
            if (empty($userId) || empty($resource)) {
                return 'denied';
            }
            // Globally allowed resources; Checking
            $globalResources = array('UploadedFile');
            if (in_array($resource, $globalResources))
                return 'add_delete';
            // Restricted resources; Checking
            $conditions = array(
                'user_id' => $userId,
                'or' => array(
                    array('resource' => 'All'),
                    array('resource' => $resource),
                )
            );
            if ($resource == 'Event') {
                array_push($conditions['or'], array('resource' => 'Category'));
            }
            if (!empty($resourceId)) {
                $conditions['or'] = array(
                    array('resource' => 'All'),
                    array('resource' => $resource, 'resource_id' => null),
                    array('resource' => $resource, 'resource_id' => $resourceId)
                );
                if ($resource == 'Event') {
                    $this->User->Membership->Team->Event->unbindModel(array('hasMany' => array('Team')));
                    $this->User->Membership->Team->Event->bindModel(array('belongsTo' => array(
                        'Category' => array(
                            'fields' => 'Category.id'
                        )
                    )));
                    $event = $this->User->Membership->Team->Event->find('first', array('conditions' => array('Event.id' => $resourceId), 'recursive' => 1));
                    if (!empty($event)) {
                        array_push($conditions['or'], array('resource' => 'Category', 'resource_id' => null));
                        array_push($conditions['or'], array('resource' => 'Category', 'resource_id' => $event['Category']['id']));
                    }
                }
            }
            $permission = $this->find('first', array('conditions' => $conditions));
            if (empty($permission)) {
                return 'denied';
            } else if ($permission['Permission']['resource_id'] != null) {
                return 'view_edit';
            } else {
                return 'add_delete';
            }
        }

        function fetchResources($userId = null) {
            $data = $this->find('all', array('conditions' => array('user_id' => $userId), 'fields' => 'DISTINCT (Permission.resource)'));
            $return = array();
            foreach ($data as $datum) {
                array_push($return, $datum['Permission']['resource']);
                if ($datum['Permission']['resource'] == 'Category') {
                    array_push($return, 'Event');
                }
            }
            return $return;
        }

}
?>