#!/bin/sh

sleep 5
mysql --host=mysql-service --user=admin --password=admin wordpress < /tmp/wordpress.sql  #wordpress table made with wordpress.sql
