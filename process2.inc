<?php
$username="web";
$password="Nebb20102010#";
$conn=oci_connect($username, $password, '(description= (retry_count=20)(retry_delay=3)(address=(protocol=tcps)(port=1522)(host=adb.eu-frankfurt-1.oraclecloud.com))(connect_data=(service_name=dvlll27ur8jgctu_db202001232013_high.atp.oraclecloud.com))(security=(ssl_server_cert_dn="CN=adwc.eucom-central-1.oraclecloud.com,OU=Oracle BMCS FRANKFURT,O=Oracle Corporation,L=Redwood City,ST=California,C=US")))','UTF8');
$key=$_POST['key'];                                                                                                                                                                                                                                                                                          
if (!$conn)  { $e = oci_error(); trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR); exit(1); }
//$key=substr(sha1(rand()),0,40);


//$current="Hellrox: $index :".$_POST['test'];
//$image=file_put_contents('/www/test.txt', $current);
//$tmp=$_FILES['files']['tmp_name'][1];

if (isset($_POST['desc'])) $desc=$_POST['desc'];
else $desc=NULL;
if ($desc!=NULL) {
$keys=$key;
$query = "INSERT INTO MAIN (MAIN,KEYS,STAMP) values ('$desc','$keys',sysdate)";
$result = oci_parse ($conn, $query);
oci_execute($result); oci_free_statement($result);

//file_put_contents('/www/test.txt', $file_path);

}
$query2 = "INSERT INTO OBJECT (KEY,STAMP,BLOB) VALUES('$key',sysdate,empty_blob()) RETURNING blob INTO :image";
$result = oci_parse($conn, $query2);
$blob = oci_new_descriptor($conn, OCI_D_LOB);
oci_bind_by_name($result, ":image", $blob, -1, OCI_B_BLOB);
oci_execute($result, OCI_DEFAULT) or die ("Unable to execute query2");

if(!$blob->save(file_get_contents($uploaded_file))) {
    oci_rollback($conn);
}
else {
    oci_commit($conn);
}

oci_free_statement($result);
$blob->free();


?>
