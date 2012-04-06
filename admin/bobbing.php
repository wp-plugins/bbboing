<?php 

/**
 * activation function for the bobbing plugin
 *
 * bobbing is dependent upon oik - for trace and the oik_depends() function
 * it then uses oik_depends() to check its dependencies on other plugins. 
 * In this case "bbboing"
 * 
 *
 * @param string $arg1 - the file name for this plugin
 * @param string $arg2 - future use
 * @param string $arg3 - future use
 *
 * @uses bw_trace2() to show that it's working
 * @uses bw_backtrace() to show the function call stack
 * @uses oik_depends() to perform the active plugin dependency checking
 * @uses trigger_error() for when oik is not activated
*/
function bobbing_lazy_activation( $arg1=null, $arg2=null, $arg3=null ) {
 bw_trace2();
 bw_backtrace(); 

 if ( function_exists( "oik_depends" ) ) {  
   /* Good - oik appears to be activated and loaded */
   oik_depends( $arg1, "bbboing" );
 } else {
   trigger_error( "bobbing is dependent upon 'oik' and the following plugins: bbboing" );  
   // _doing_it_wrong( __FUNCTION__, "bobbing is dependent upon the oik and bbboing plugins", "3.3.1" );  
   // bobbing_is_dependent_upon_oik();
   
 }   
}

