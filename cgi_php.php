#! /usr/bin/php
<?php
$name = [];
$value = [];
echo 'Status: 200';
echo "\r\n\r\n";
$pair = explode('&', $_ENV["QUERY_STRING"]);
echo "METHOD -> " . $_ENV["REQUEST_METHOD"] . "\r\n\r\n";
for ($i = 0; $i < count($pair); $i++)
{
	$split = explode('=', $pair[$i]);
	$name[$i] = $split[0];
	$value[$i] = $split[1];
}

for ($i = 0; $i < count($name); $i++)
{
	echo "<h2>" . $name[$i] . ": ". $value[$i] . "</h2>\r\n";
}
?>
