<?php
/* SVN FILE: $Id: app_controller.php 7945 2008-12-19 02:16:01Z gwoo $ */
/**
 * Short description for file.
 *
 * This file is application-wide controller file. You can put all
 * application-wide controller-related methods here.
 *
 * PHP versions 4 and 5
 *
 * CakePHP(tm) :  Rapid Development Framework (http://www.cakephp.org)
 * Copyright 2005-2008, Cake Software Foundation, Inc. (http://www.cakefoundation.org)
 *
 * Licensed under The MIT License
 * Redistributions of files must retain the above copyright notice.
 *
 * @filesource
 * @copyright     Copyright 2005-2008, Cake Software Foundation, Inc. (http://www.cakefoundation.org)
 * @link          http://www.cakefoundation.org/projects/info/cakephp CakePHP(tm) Project
 * @package       cake
 * @subpackage    cake.cake.libs.controller
 * @since         CakePHP(tm) v 0.2.9
 * @version       $Revision: 7945 $
 * @modifiedby    $LastChangedBy: gwoo $
 * @lastmodified  $Date: 2008-12-18 18:16:01 -0800 (Thu, 18 Dec 2008) $
 * @license       http://www.opensource.org/licenses/mit-license.php The MIT License
 */
/**
 * This is a placeholder class.
 * Create the same file in app/app_controller.php
 *
 * Add your application-wide methods in the class below, your controllers
 * will inherit them.
 *
 * @package       cake
 * @subpackage    cake.cake.libs.controller
 */
class AppController extends Controller {
    var $helpers = array('Html', 'Form', 'Javascript');
    var $components = array('Auth');
    var $layout = 'main';
    var $uses = array('Category');

    function beforeFilter() {
        $this->Auth->fields = array(
            'username' => 'email',
            'password' => 'password'
        );
        if (isset($this->params['admin'])) {
            $this->layout = 'admin';
            if ($this->Auth->user()) {
                if ($this->Auth->user('privilege') < 1) {
                    $this->redirect(array('controller' => 'users', 'action' => 'logout', 'admin' => 0));
                }
                $this->loadModel('Permission');
                $permissionsCount = $this->Permission->find('count');
                if ($permissionsCount != 0) {
                    $allowedResources = $this->Permission->fetchResources($this->Auth->user('id'));
                    if (!empty($this->params['pass']['0'])) {
                        $access = $this->Permission->check($this->Auth->user('id'), Inflector::classify($this->name), $this->params['pass']['0']);
                    } else {
                        $access = $this->Permission->check($this->Auth->user('id'), Inflector::classify($this->name));
                    }
                    // $access can be denied / view_edit / add_delete
                    if ($this->params['action'] != 'admin_logout' &&
                        ($access == 'denied' ||
                        ($access == 'view_edit' && ($this->params['action'] == 'admin_add' || $this->params['action'] == 'admin_delete')))) {
                        $this->redirect('/admin/uploaded_files/home');
                    }
                }
                $this->set(compact('permissionsCount', 'allowedResources'));
            }
        } else if ($this->layout != false) {
            
           
                $this->layout = 'main';
           
            $this->set('categories_for_layout', $this->Category->fetchMenu());
        }
    }

    function __errorOccurred($message = 'An error occurred.', $redirect = array('controller' => 'users', 'action' => 'index')) {
        $this->Session->setFlash($message);
        $this->redirect($redirect);
        exit();
    }

    function __processCompleted($message = 'Success!', $redirect = array('controller' => 'users', 'action' => 'index')) {
        $this->Session->setFlash($message);
        $this->redirect($redirect);
        exit();
    }

    function __debugPrintArray($array) {
        echo '<pre>'; print_r($array); echo '</pre>';
    }

}
?>