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

if(isset($_POST["temp"]) && isset($_POST["temp_bmp"]) && isset($_POST["hum"]) && isset($_POST["pres"])) {

	$temp = $_POST["temp"];
	$temp_bmp = $_POST["temp_bmp"];
	$hum = $_POST["hum"];
	$pres = $_POST["pres"];

	$insert = "INSERT INTO measurements (temp, temp_bmp, hum, pres) VALUES (".$temp.", ".$temp_bmp.", ".$hum.", ".$pres.")";

	if (mysqli_query($conn, $insert)) {
		echo "New record created";
	} else {
		echo "Error: " . $sql . "<br>" . mysqli_error($conn);
	}
}

?>