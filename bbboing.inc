<?php // (C) Copyright Bobbing Wide 2010-2012

/**
 * Implementation of the bbboing shortcode 
*/
function bbboing_sc( $atts=NULL ) {
  $form = bw_array_get( $atts, "form", 'N' );
  $both = bw_array_get( $atts, "both", 'N' );
  $text = bw_array_get_dcb( $atts, "text", "", "seed" );
  $form = bw_validate_torf( $form );
  $both = bw_validate_torf( $both );
  if ( $form )
    $result = _bbboing_form( $text, $atts );
  else
    $result = _bbboing_static( $text, $both );
  return( $result );
}

/**
 * Display the original text and the bbboing'ed text if both=TRUE, otherwise just the bbboing'ed text 
 * 
 * @param string $text - the text to bbboing
 * @param bool $both - when true display the Original and bbboing'ed text, when false just the bbboing'ed text.
 * @return string the result of the shortcode
 */
function _bbboing_static( $text=NULL, $both=false ) {
  if ( $both ) {
    h4( "Original text" );
    p( $text );
    h4( "bbboing'ed" );
  }
  p( bbboing( $text ));
  return( bw_ret());
}


/** 
 * This is the text that is used if the text= parameter is not specified
 * @return string $bnobbig - the 'correct' original text to be obfuscated
*/ 
function seed() {
  $bnobbig = "According to a researcher at Cambridge University it doesn't matter in what order the letters in a word are ,";
  $bnobbig.= " the only important thing is that the first and last letter be at the right place .";
  $bnobbig.= " The rest can be a total mess and you can still read it without problem ."; 
  $bnobbig.= " This is because the human mind does not read every letter by itself but the word as a whole .";
  return( $bnobbig );
}


/** 
 * Note that in this 'original' version "rscheearch" is not an anagram of "researcher" and it breaks the rules
 * that the first and last letters should be in the right place. It does at least have the right number of letters.
*/ 
function hoax_version()
{
  $bnobbig = "According to a researcher at Cambridge University it doesn't matter in what order the letters in a word are";
  
  $bnobbig = "Aoccdrnig to a rscheearch at Cmabrigde Uinervtisy, it deosn't mttaer in waht oredr the ltteers in a wrod are ,";
  $bnobbig.= " the olny iprmoetnt tihng is taht the frist and lsat ltteer be at the rghit pclae .";
  $bnobbig.= " The rset can be a toatl mses and you can sitll raed it wouthit porbelm . ";
  $bnobbig.= " Tihs is bcuseae the huamn mnid deos not raed ervey lteter by istlef but the wrod as a wlohe. ";
  return( $bnobbig );
}   

function _bbboing_get( $text=NULL ) {
  $text = bw_array_get( $_REQUEST, "_bbboing_text", $text );
  $text = strip_tags( $text );
  return $text;
}     
 
function _bbboing_form( $text=NULL, $atts=NULL ) {
  oik_require( "bobbforms.inc" );
  $text = _bbboing_get( $text );  
  $cols = bw_array_get( $atts, "cols", 40 );
  e( '<form method="post" action="" class="inline">' );
  p( "Type the text you want to obfuscate then click on 'bbboing it'" );
  bw_textarea( "_bbboing_text", $cols, NULL, $text );
  br();
  e( "<input type=\"submit\" name=\"_bbboing_ok\" value=\"bbboing it\" />" );
  p("This is the result of <i>bbboing</i>ing the text." ); 
  bw_textarea( "_bbboinged", $cols, NULL ,   bbboing( $text ) );
  p( "If you're not happy with the result just click on 'bbboing it'!" );
  etag( "form" );
  return( bw_ret());
}

function bbboing( $text ) {
   $bbtext = '';
   $words = explode( ' ', $text );
   foreach ( $words as $word )
   {
      $bbtext.= bboing($word );   
      $bbtext.= " ";
   }
   return( $bbtext );
}

function bboing( $word ) {
   
  if ( ctype_alpha( $word ) )
  {
    // echo "c";
    $word = boing( $word ); 
  }  
  else
  {
    $count = strlen( $word );
   
    $l = substr( $word, 0, 1 );
    if ( $l <> "<" ) 
    {
      $r = substr( $word, $count-1 ); 
      $pos = strpos( ".?:-", $r );

      
      if ($pos === FALSE )
      {
         
         $word = boing( $word ); 
      }   
      else  
      { 
         $word = boing( substr( $word, 0, $count-1 )) . $r;
      }   
    }
  } 
  return( $word );
}


function boing( $word ) {
  // echo $word . "\n";
  $count = strlen( $word );
  switch ( $count )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      // Can't do anything with this length word
      $wrod = $word;
    break;

    default:
      $l = substr( $word, 0, 1 );
      $r = substr( $word, $count-1 ); 
      $mid = substr( $word, 1, $count-2 ); 
    
      $dim = str_shuffle( $mid );
      $wrod = $l . $dim . $r;
    break;
  }    
  return( $wrod );
}


/** 
 * Help for bbboing
*/
function bbboing__help( ) {
 return( "Obfuscate some text but leave it readable, apparently" );
 gobang();
} 

/**
 * Syntax for bbboing
 *
*/
function bbboing__syntax( ) {
  $syntax = array( "text" => bw_skv( "seed", "text", "some text to obfuscate" )
                 , "form" => bw_skv( "N", "Y", "display form to allow changes" )
                 , "both" => bw_skv( "N", "Y", "display both original and output text" )
                 );
  return( $syntax );
}

/**
 *
 * Example: 
 *  [bbboing text="and this is where it shows the before and after" both='Y']
 * 
 */
function bbboing__example( ) {
  e ( _bbboing_static( seed() ) );
  h4( "The manual version" );
  p( "This is the original obfuscated text. It has been manually adjusted to make it readable." );
  p( hoax_version() );
}                 


 

