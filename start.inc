<?php
$i=0;
$query="SELECT * from (SELECT main,keys,to_char(stamp,'YYYY-MM-DD HH24:MI:SS') as stamp,(SELECT count(key) from object where key in keys) from MAIN order by stamp desc) where ROWNUM<=10" ;
$result = oci_parse ($conn, $query);
echo "<h1>Welcome to InnoLab Cloud Chapter</h1>";
	if ($debug==1) echo "<div class='debug'>$query</div>";
oci_execute($result);
while (list ($main,$keys,$stamp,$has_blob) = oci_fetch_row ($result)) { $i++;
        if ($i==1) echo "<div id='container'></div><table class='blueTable'><thead><tr><th>NR</th><th>DESC</th><th>KEYS</th><th>STAMP</th><th>HAS_BLOB</th></tr></thead><tbody>";
        echo "<tr data-href='?show_image=$keys'><td>$i</td><td>$main</td><td>$keys</td><td>$stamp</td><td>$has_blob</td></tr>"; }
echo "</tbody></table>";
show_form($desc,$object1);
oci_free_statement($result);
oci_close($conn);
?>
