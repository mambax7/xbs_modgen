<?php declare(strict_types=1);

/*
 * You may not change or alter any portion of this comment or credits
 * of supporting developers from this source code or any supporting source code
 * which is considered copyrighted (c) material of the original comment or credit authors.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

/**
 * Admin Menu item definition
 *
 * @copyright     Ashley Kitson
 * @copyright     XOOPS Project https://xoops.org/
 * @license       GNU GPL 2 or later (http://www.gnu.org/licenses/gpl-2.0.html)
 * @author        Ashley Kitson http://akitson.bbcb.co.uk
 * @author        XOOPS Development Team
 * @package       XBS_MODGEN
 * @subpackage    Admin
 * @version       1
 * @access        private
 */

use XoopsModules\Xbsmodgen\{Utility
};

/**
 * Do all the declarations etc needed by an admin page
 */
require_once __DIR__ . '/admin_header.php';
//require_once __DIR__ . '/adminheader.php';

//check to see if we have a selected module to work with
if (!isset($_SESSION['xbsmodgen_mod'])) {
    //redirect to module choosing page

    redirect_header(XBS_MODGEN_URL . '/admin/admenu1.php', 1, _AM_XBSMODGEN_ADMINMSG3);
}
//Display the admin menu
//xoops_module_admin_menu(4,_AM_XBSMODGEN_ADMENU4);

/**
 * admin menu common processing
 */
require __DIR__ . '/common.php';

if ($edit) { //User has selected a menu to edit
    Utility::adminEditMenu($_SESSION['xbsmodgen_mod'], 'amenu', $id);
} elseif ($insert) {
    //create a new menu item

    Utility::adminEditMenu($_SESSION['xbsmodgen_mod'], 'amenu');
} elseif ($save) {
    //user has edited or created a menu so save it

    $ret = Utility::adminSaveMenu($clean, 'amenu');

    if ($ret > 0) {
        redirect_header(XBS_MODGEN_URL . '/admin/admenu4.php', 1, _AM_XBSMODGEN_ADMINMSG4);
    } else {
        //should never get here as redirection occurs

        // in adminSaveMenu on error

        die('Oops - should not have got here #1 - admenu4.php');
    }
} elseif ($del) {
    if (adminDelMenu($id, 'amenu')) {
        redirect_header(XBS_MODGEN_URL . '/admin/admenu4.php', 1, _AM_XBSMODGEN_ADMINMSG5);
    } else {
        //should never get here as redirection occurs

        // in adminDelMenu on error

        die('Oops - should not have got here #2 - admenu4.php');
    }
} elseif ($cancel) {
    redirect_header(XBS_MODGEN_URL . '/admin/admenu4.php', 1, _AM_XBSMODGEN_ADMINERR1);
} else {
    //Present a list of menus for the module to select to work with

    Utility::adminSelectMenu('amenu');
} //end if

//And put footer in
xoops_cp_footer();
