<?php
/*  XBS Modgen Module shell generator for Xoops CMS
    Copyright (C) 2006 Ashley Kitson, UK
    admin at xoobs dot net

    This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/**
 * XBS Modgen Module shell generator for Xoops CMS
 * 
 * Header file required for all pages
 * 
 * @author Ashley Kitson (http://xoobs.net)
 * @copyright 2006 Ashley Kitson, UK
 * @package XBS_MODGEN
 * @subpackage Xoops
 * @access public
 * 
 */

if (file_exists("../../mainfile.php")) {
	/**
	* Xoops required include
	*/
	include_once("../../mainfile.php");
} elseif (file_exists("../../../mainfile.php")) {
	/**
	 * @ignore 
	 */
	include_once("../../../mainfile.php");
} else {
	die("Unable to locate Xoops Mainfile");
}

//Load CDM definitions
if (file_exists(XOOPS_ROOT_PATH."/modules/xbs_cdm/include/defines.php")) {
	/**
	 * Require Code Data Management module definitions
	 */
	require_once(XOOPS_ROOT_PATH."/modules/xbs_cdm/include/defines.php");
} elseif (file_exists(XOOPS_ROOT_PATH."/modules/xbs_cdm/include/defines.inc")) {
	/**
	 * @ignore 
	 */
	require_once(XOOPS_ROOT_PATH."/modules/xbs_cdm/include/defines.inc");
} else {
	die("Unable to locate CDM Definitions");
}

//Load XBS_MODGEN definitions
if (file_exists(XOOPS_ROOT_PATH."/modules/xbs_modgen/include/defines.inc")) {
	/**
	 * XBS_Modgen non language specific constant definitions
	 */
	require_once(XOOPS_ROOT_PATH."/modules/xbs_modgen/include/defines.inc");
} else {
	die("Unable to locate ModGen Definitions");
}

//Load XBS_MODGEN functions
if (file_exists(XBS_MODGEN_PATH."/include/functions.inc")) {
	/**
	 * XBS_Modgen common functions
	 */
	require_once(XBS_MODGEN_PATH."/include/functions.inc");
} else {
	die("Unable to locate ModGen Common Functions");
}

//Load form elements
if (file_exists(XBS_MODGEN_PATH."/class/class.xbs_modgen.form.inc")) {
	/**
	* XBS_MODGEN Form elements
	*/
	require_once XBS_MODGEN_PATH."/class/class.xbs_modgen.form.inc";
} else {
	die("Unable to locate ModGen Form Elements");
}

?>