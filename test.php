<?php
require_once ('config.inc');
$key = 1;
$image=file_get_contents("/bin/echo");
$show_image=null;
$query="SELECT key,stamp,blob from OBJECT where key='d0e565d0d07b45e24432f10ef5896ee7b8e170bf'";
echo $query;
$result = oci_parse ($conn, $query);
oci_execute($result) or die ("Unable to fetch image $show_image");
while (list ($a,$b,$c) = oci_fetch_row ($result)) { 
	$c=$c->load();
	echo '<img src="data:image/jpeg;base64,'.base64_encode( $c ).'"/>';

						  }
oci_free_statement($result);

?>
