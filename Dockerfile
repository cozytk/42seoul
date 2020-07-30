FROM	debian:buster

RUN		apt-get update && \ 
		apt-get -y install nginx openssl vim wget php-fpm mariadb-server php-mysql wget
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

COPY	./srcs/init_container.sh ./
COPY	./srcs/config.inc.php ./config.inc.php
COPY	./srcs/default etc/nginx/sites-available/default
COPY	./srcs/wp-config.php ./wp-config.php

CMD		bash init_container.sh
