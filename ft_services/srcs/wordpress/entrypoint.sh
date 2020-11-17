#!/bin/sh

sh /tmp/launch-wordpress.sh
php-fpm7 &
nginx -g 'daemon off;' 
