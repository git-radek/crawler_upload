<?php
function convert_to_webp($jpeg_input) {
$image=imagecreatefromjpeg($jpeg_input);
ob_start();
imagejpeg($image,NULL,100);
$cont=ob_get_contents();
ob_end_clean();
imagedestroy($image);
$content = imagecreatefromstring($cont);
//ob_start();
imagewebp($content,"costam.webp");
//$webp_output=ob_get_contents();
//ob_end_clean();
//return $webp_output;
imagedestroy($content);
                           }
?>
