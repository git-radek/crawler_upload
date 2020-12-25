<?php
$username="web";
$password="Nebb20102010#";
$conn=oci_connect($username, $password, '(description= (retry_count=20)(retry_delay=3)(address=(protocol=tcps)(port=1522)(host=adb.eu-frankfurt-1.oraclecloud.com))(connect_data=(service_name=dvlll27ur8jgctu_db202001232013_high.atp.oraclecloud.com))(security=(ssl_server_cert_dn="CN=adwc.eucom-central-1.oraclecloud.com,OU=Oracle BMCS FRANKFURT,O=Oracle Corporation,L=Redwood City,ST=California,C=US")))','UTF8');

if (!$conn)  { $e = oci_error(); trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR); exit(1); }
$key=substr(sha1(rand()),0,40);
?>
