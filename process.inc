<?php
$tmp=$_FILES['object1']['tmp_name'][1];
$image=file_get_contents($tmp);
$imageattr=list($width, $height, $mime, $attr) = getimagesize($tmp);
if($image_attr !== false) {
        $size="File is an image - " . $mime . ".";
        if (($width<=800)&&($height<=600)) $error="Image has to be at least 800x600 ($width x $height)";
                          }
else { $error="File has to be an image"; $size = "File is not an image."; }

if (isset($error)) { echo "<h1> $error </h1>"; }

else {
$keys=$key;

$query = "INSERT INTO MAIN (MAIN,KEYS,STAMP) values ('$desc','$keys',sysdate)";
$result = oci_parse ($conn, $query);
oci_execute($result); oci_free_statement($result);


$query2 = "INSERT INTO OBJECT (key,stamp,blob) VALUES('$key',sysdate,empty_blob()) RETURNING blob INTO :image";
$result = oci_parse($conn, $query2);
$blob = oci_new_descriptor($conn, OCI_D_LOB);
oci_bind_by_name($result, ":image", $blob, -1, OCI_B_BLOB);
oci_execute($result, OCI_DEFAULT) or die ("Unable to execute query2");

if(!$blob->save($image)) {
    oci_rollback($conn);
}
else {
    oci_commit($conn);
}

oci_free_statement($result);
$blob->free();

echo "<div id='debug'>Posted $desc<br>
Key: $key<br>
Object1: $object1<br>
Name: $tmp<br>
Size: $size/$width x $height<br>
Query1: $query<br>
Query2: $query2</div>
<div style='clear: both'></div>
";

}
?>
