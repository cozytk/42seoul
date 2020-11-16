#!/bin/sh

usr/bin/telegraf &

sleep 5
sh /launch-wordpress.sh
php -S 0.0.0.0:5050 -t /etc/wordpress/
until [ $? != 1 ] #until process does not exit
do
	php -S 0.0.0.0:5050 -t /etc/wordpress/ #starting with a specifir document root directory
done
