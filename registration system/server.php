<?php
session_start();

$username="";
$errors = array();

//connect to mysql database
$db=mysqli_connect(null,'root', 'MFys980304','registration',null,'/cloudsql/s3548974-cc2018:australia-southeast1:cloud');

//Register USER
if(isset($_POST['reg_user'])){
	//receive all input values from the form
	$username = mysqli_real_escape_string($db,$_POST['username']);
	$password_1 = mysqli_real_escape_string($db, $_POST['password_1']);
	$password_2 = mysqli_real_escape_string($db,$_POST['password_2']);
	
	// form validation: ensure that the form is correctly filled ...
    // by adding (array_push()) corresponding error unto $errors array
	if(empty($username))
	{
	  array_push($errors,"Username is required");
	}
	if(empty($password_1))
	{
	  array_push($errors,"Password is required");
	}
	if($password_1 != $password_2)
	{
		array_push($errors, "Password do not match");
	}
	//Check whether a user already exist with same username
	$user_check_query = "SELECT * FROM users WHERE username='$username'";
	$result = mysqli_query($db,$user_check_query);
	$user = mysqli_fetch_assoc($result);
	
	if($user){
		if($user['username'] === $username){
			array_push($errors, "Username already exists");
		}
	}
	if(count($errors)==0)
	{
	    $password = md5($password_1);//encrypt the password
		$query = "INSERT INTO users(username,password)
		          VALUES('$username','$password')";
		mysqli_query($db, $query);
		$_SESSION['username']=$username;
		$_SESSION['success']="You are now logged in";
		header('location: index.php');
	}
}

//Login user
  if(isset($_POST['login_user']))
  {
      $username=mysqli_real_escape_string($db, $_POST['username']);
      $password = mysqli_real_escape_string($db, $_POST['password']);
	  
	  if(empty($username)){
		  array_push($errors, "Username is required");
	  }
	  if(empty($password)){
		  array_push($errors, "Password is required");
	  }
	  if(count($errors) == 0)
	  {
		  $password = md5($password);
		  $query="SELECT * FROM users WHERE username='$username' AND password='$password'";
	      $results=mysqli_query($db, $query);
		  if(mysqli_num_rows($results) == 1)
		  {
			  $_SESSION['username'] = $username;
			  $_SESSION['success'] = "You are now logged in";
			  header('location: index.php');
		  }
		  else{
			  array_push($errors, "Wrong username/password");
		  }
	  }
  }
  ?>