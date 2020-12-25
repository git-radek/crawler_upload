<?php
$query="SELECT * from OBJECT where key='$show_image'";
$result = oci_parse ($conn, $query);
oci_execute($result) or die ("Unable to fetch image $show_image");
while (list ($a,$b,$c) = oci_fetch_row ($result)) {
        $c=$c->load();
        echo "<div style='background-color: #FFFDAF'>";
		if ($debug==1) echo "<div class='debug'>$query</div>";
	echo "<div><img style='display: block; margin: 0 auto' src='data:image/jpeg;base64,".base64_encode( $c )."'/></div></div>";
                                                  }
oci_free_statement($result);
?>
