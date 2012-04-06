=== bbboing ===
Contributors: bobbingwide
Donate link: http://www.oik-plugins.com/oik/oik-donate/
Tags: shortcode, obfuscate 
Requires: 3.0.4
Tested up to: 3.3.1
Stable tag: trunk

obfuscate text but leave it readable

== Description ==
Aoccdrnig to a rscheearch at Cmabrigde Uinervtisy, it deosn't mttaer in waht oredr the ltteers in a wrod are, the olny iprmoetnt tihng is taht the frist and lsat ltteer be at the rghit pclae.
The rset can be a toatl mses and you can sitll raed it wouthit porbelm.
Tihs is bcuseae the huamn mnid deos not raed ervey lteter by istlef but the wrod as a wlohe.

This plugin implements a version of an algorithm that will produce text similar to the above.
Basically it changes each word by randomising the order of the letters, leaving the first and last letter of each word the same.

You implement this on your website using the [bbboing] shortcode.

The syntax is:


[bbboing
  text="seed|text - some text to obfuscate"
  form="N|Y - display form to allow changes"
  both="N|Y - display both original and output text"]

If you don't specify any parameters you get a 'bbboing'ed version of the original text.

Examples:
 [bbboing text="code is poetry"] may produce 'code is peroty' or 'cdoe is pretoy'
 [bbboing text='powered by WordPress'] may produce 'prweoed by WrdsorPes'
 
It's also feasible that the randomisation produces exactly the same output as input. 
So [bbboing text='bobbing wide'] may produce bobbing wide

Of course, nothing happens for words with fewer than 4 letters so
[bbboing text='it is not a con'] WILL produce the same output as input.

You may notice that some spammers/spambots intentionally misspell words when creating comments.
bbboing does not in anyway endorse this. 

Please use bbboing for your own amusement.

== Installation ==
1. Upload the contents of the bbboing plugin to the `/wp-content/plugins/bbboing' directory
1. Activate the bbboing plugin through the 'Plugins' menu in WordPress
1. Whenever you want to produce some 'bbboing'ed text use the [bbboing] shortcode.

== Frequently Asked Questions ==
= Where does bbboing come from? =
bbboing is an anagram of bobbing, which is part of my company name ( bobbing wide - hence my WordPress.org username ). 
Furthermore it's an anagram where the first and last letters of the word are not changed.
'bbboing' is just one of the possible results of running the algorithm against 'bobbing'.
= What does obfuscate mean? =
Render obscure, unclear, or unintelligible. Bewilder (someone).

= What is this plugin for? =
The purpose of this plugin is both entertaining, educational and experimental.

Entertaining in that it produces an obfuscated version of some text following the "rules" defined in http://www.mrc-cbu.cam.ac.uk/people/matt.davis/Cmabrigde/

Educational in that it shows an example of a plugin developed using the application programming interface in my oik plugin, where I have been developing the idea of smart lazy shortcodes.
* smart - the shortcodes understand the content in which they're invoked
* lazy - the code to evaluate the shortcode is loaded on demand, when the shortcode is used.

Experimental since I am trying to find a good approach for dealing with plugin dependency.
The bobbing plugin that comes with bbboing is dependent upon oik and bbboing.

= Can you tell me more about the research? =
See http://www.mrc-cbu.cam.ac.uk/people/matt.davis/Cmabrigde/

== Screenshots ==
1. 

== Upgrade Notice ==

== Changelog ==
= 0.1 =
* initial version. Works with oik version 1.11 


== Further reading ==
If you want to read more about the oik plugins then please visit the
[oik plugin](http://www.oik-plugins.com/oik) 
**"the oik plugin - for often included key-information"**



