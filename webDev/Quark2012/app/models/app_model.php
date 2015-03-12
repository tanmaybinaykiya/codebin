<?php
/* SVN FILE: $Id: app_model.php 7945 2008-12-19 02:16:01Z gwoo $ */
/**
 * Application model for Cake.
 *
 * This file is application-wide model file. You can put all
 * application-wide model-related methods here.
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
 * @subpackage    cake.cake.libs.model
 * @since         CakePHP(tm) v 0.2.9
 * @version       $Revision: 7945 $
 * @modifiedby    $LastChangedBy: gwoo $
 * @lastmodified  $Date: 2008-12-18 18:16:01 -0800 (Thu, 18 Dec 2008) $
 * @license       http://www.opensource.org/licenses/mit-license.php The MIT License
 */
/**
 * Application model for Cake.
 *
 * This is a placeholder class.
 * Create the same file in app/app_model.php
 * Add your application-wide methods to the class, your models will inherit them.
 *
 * @package       cake
 * @subpackage    cake.cake.libs.model
 */
class AppModel extends Model {

	var $recursive = -1;
	var $cacheQueries=true;
	function getEnumValues($columnName=null, $respectDefault=false)
	{
		if ($columnName==null) { return array(); } //no field specified


		//Get the name of the table
		$db =& ConnectionManager::getDataSource($this->useDbConfig);
		$tableName = $db->fullTableName($this, false);


		//Get the values for the specified column (database and version specific, needs testing)
		$result = $this->query("SHOW COLUMNS FROM {$tableName} LIKE '{$columnName}'");

		//figure out where in the result our Types are (this varies between mysql versions)
		$types = null;
		if     ( isset( $result[0]['COLUMNS']['Type'] ) ) { $types = $result[0]['COLUMNS']['Type']; $default = $result[0]['COLUMNS']['Default']; } //MySQL 5
		elseif ( isset( $result[0][0]['Type'] ) )         { $types = $result[0][0]['Type']; $default = $result[0][0]['Default']; } //MySQL 4
		else   { return array(); } //types return not accounted for

		//Get the values
		$values = explode("','", preg_replace("/(enum)\('(.+?)'\)/","\\2", $types) );

		if($respectDefault){
			$assoc_values = array("$default"=>Inflector::humanize($default));
			foreach ( $values as $value ) {
				if($value==$default){ continue; }
				$assoc_values[$value] = Inflector::humanize($value);
			}
		}
		else{
			$assoc_values = array();
			foreach ( $values as $value ) {
				$assoc_values[$value] = Inflector::humanize($value);
			}
		}

		return $assoc_values;

	} //end getEnumValues
}
?>