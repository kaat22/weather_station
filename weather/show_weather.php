<?php
$hostname = "localhost";
$username = "root";
$database = "temp_sensor_db";
$password = "";

$conn = mysqli_connect($hostname, $username, $password, $database);

if (!$conn) {
	die("connection not established: " . mysqli_connect_error());
}

$query = mysqli_query($conn, "SELECT * FROM measurements ORDER BY id DESC LIMIT 10");
$data = $query->fetch_all(MYSQLI_ASSOC);

?>

<table border="1">
  <tr>
    <th>Temperature</th>
	<th>Temperature_bhp</th>
    <th>Humidity</th>
	<th>Pressure</th>
	<th>Time</th>
  </tr>
  <?php foreach($data as $row): ?>
  <tr>
    <td><?= htmlspecialchars($row['temp']) ?></td>
	<td><?= htmlspecialchars($row['temp_bmp']) ?></td>
    <td><?= htmlspecialchars($row['hum']) ?></td>
	<td><?= htmlspecialchars($row['pres']) ?></td>
	<td><?= htmlspecialchars($row['time']) ?></td>
  </tr>
  <?php endforeach ?>
</table>