#!/bin/sh
php-fpm7 &
nginx -g 'daemon off;'
