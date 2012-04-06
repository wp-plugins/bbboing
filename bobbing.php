<?php
/**
Plugin Name: bobbing
Plugin URI: http://www.oik-plugins.com/oik-plugins/bobbing
Depends: oik, bbboing
Description: a sample plugin that's dependent upon oik and bbboing
Version: 1.0
Author: bobbingwide
Author URI: http://www.bobbingwide.com
License: GPL2

    Copyright 2012 Bobbing Wide (email : herb@bobbingwide.com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2,
    as published by the Free Software Foundation.

    You may NOT assume that you can use any other version of the GPL.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    The license for this software can likely be found here:
    http://www.gnu.org/licenses/gpl-2.0.html

*/
add_action( "oik_loaded", "bobbing_init" );

register_activation_hook( __FILE__, "bobbing_activation" );

function bobbing_init( ) {
  bw_trace2();
}

function bobbing_activation() {
  bw_trace2();
  require_once( "admin/bobbing.php" );
  bobbing_lazy_activation( __FILE__ );
 
}

