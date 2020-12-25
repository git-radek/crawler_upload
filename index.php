<?php
error_reporting(E_ALL | E_STRICT);
$time_start = microtime(true);
$request=$_SERVER['REQUEST_URI'];
//if (isset($_GET['debug'])) $debug=$_GET['debug'];
$debug=1;

require "config.inc";
require "header.inc";
require "footer.inc";

global $conn;

function show_form($desc=NULL,$object1=NULL) {
echo "<form method=post action=/>
<div><textarea id='desc' name='desc'>".(($desc==NULL) ? 'Add description here' : $desc)."</textarea></div>";
?>
<div><input id="fileupload" type="file" name="files[]" data-url="/?img_process=start" multiple></div>
<div><input id='submit' type='submit' name='submit'></div>
</form>
<?php
}


if (isset($_POST['desc']))                 $desc=$_POST['desc']; else $desc=NULL;
if (isset($_POST['submit']))               $submit=$_POST['submit']; else $submit=NULL;
if (isset($_FILES['object1']['name'][1]))  $object1=$_FILES['object1']['name'][1]; else $object1=NULL;
if (isset($_GET['show_image']))            $show_image=$_GET['show_image']; else $show_image=NULL;
if (isset($_GET['img_process']))           $img_process=$_GET['img_process']; else $img_process=NULL;


if     ($show_image!=NULL)                                { require_once ("show_image.inc"); exit(0); }
elseif ($img_process!=NULL)                               { require_once ('img_process.inc'); $upload_handler = new UploadHandler(); exit(0);}
//elseif ($submit!=NULL && ($desc==NULL || $object1==NULL)) { show_header(); echo "<h1> ERROR: You need to add description and file </h1>"; show_footer($time_start); }
elseif ($submit!=NULL && $desc!=NULL && $object1!=NULL)   { show_header(); require_once ('process2.inc'); show_footer($time_start); }
else                                                      { show_header(); echo "<button id='debug_switch'>Show debug</button>"; require_once('start.inc'); show_footer($time_start); }


