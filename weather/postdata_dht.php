<?php

$hostname = "localhost";
$username = "root";
$database = "temp_sensor_db";
$password = "";

$conn = mysqli_connect($hostname, $username, $password, $database);

if (!$conn) {
	die("connection not established: " . mysqli_connect_error());
}

echo "database connected<br>";

if(isset($_POST["temp"]) && isset($_POST["hum"])) {

	$temp = $_POST["temp"];
	$hum = $_POST["hum"];

	$insert = "INSERT INTO dht22 (temp, hum) VALUES (".$temp.", ".$hum.")";

	if (mysqli_query($conn, $insert)) {
		echo "New record created";
	} else {
		echo "Error: " . $sql . "<br>" . mysqli_error($conn);
	}
}

?>