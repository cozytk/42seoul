FROM	debian:buster

RUN		apt-get update && \ 
		apt-get -y install nginx openssl vim wget php-fpm mariadb-server php-mysql wget

COPY	./srcs/init_container.sh ./
COPY	./srcs/config.inc.php ./config.inc.php
COPY	./srcs/default etc/nginx/sites-available/default
COPY	./srcs/wp-config.php ./wp-config.php

CMD		bash init_container.sh
