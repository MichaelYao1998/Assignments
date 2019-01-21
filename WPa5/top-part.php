<?php
session_start();
$pumps = array(
    'GP8002' => array(
        'image' => "<img src=photo/GP8002.jpg alt=''>",
        'title' => '1947 Tokheim Model 39 Cut-down',
        'description' => 'Interesting example of a post-war Tokheim Cut Down 39 (Tall). Ad glass over the window. Texaco green and red',
        'id' => 'GP8002',
        'price' => 5495
    ),
    'GB96CSUN' => array(
        'image' => "<img src=photo/GB96CSUN.gif alt=''>",
        'title' => '1938 Gilbert & Barker Model 96C Sunray',
        'description' => 'Beautiful authentic yellow and orange paint scheme highlight this Sunray Gilbert & Barker early electric gas pump.<br> Completely restored inside and out. Correct Gilbarco nozzle. Museum quality.(Rolling Stand Not Included)',
        'id' => 'GB96CSUN',
        'price' => 5495
    ),
    'RGP300A' => array(
        'image' => "<img src=photo/RGP300A.jpg alt=''>",
        'title' => '1955 Tokheim Model 300 American',
        'description' => 'Unusual American (Standard) pump from 1955. Striped paint scheme is authentic. Beautiful red and white example.',
        'id' => 'RGP300A',
        'price' => 5495
    ),
);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>pumps</title>
    <meta charset="UTF-8">
    <link href="https://fonts.googleapis.com/css?family=Fontdiner+Swanky|Graduate|Oregano" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="style.css">
    <script src="myJavascript.js"></script>
</head>
   
    