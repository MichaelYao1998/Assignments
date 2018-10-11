<?php

// Create connection
$conn = mysqli_connect(null,'root', 'MFys980304','registration',null,'/cloudsql/s3548974-cc2018:australia-southeast1:cloud');

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
$sql = "Select * from areas";
$results=mysqli_query($conn, $sql);
if(mysqli_num_rows($results)>0){
	while($row = mysqli_fetch_assoc($results)){
		echo "name: ".$row['name']. "password: ".$row['state']."xm".$row['xml'];
	}
}
	else
	{
		echo "None";
	}


mysqli_close($conn);
?>