<?php 
  session_start();
  if(isset($_SESSION['username'])){
	  header("location: index.html");
	  //header("location: test.php");
  }
  if(!isset($_SESSION['username'])){
	  $_SESSION['msg']="You must be log in first";
	  header('location:login.php');
  }
  
  ?>