FROM alpine

RUN apk --update add nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

ADD https://files.phpmyadmin.net/phpMyAdmin/4.9.6/phpMyAdmin-4.9.6-all-languages.tar.gz .
RUN tar -xvf /phpMyAdmin-4.9.6-all-languages.tar.gz
RUN rm -f /phpMyAdmin-4.9.6-all-languages.tar.gz
RUN mv /phpMyAdmin-4.9.6-all-languages /etc/phpmyadmin
RUN mkdir -p /run/nginx

COPY config.inc.php /etc/phpmyadmin
COPY entrypoint.sh /tmp/
COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 5000
ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
