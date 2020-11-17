FROM alpine

RUN apk --update add nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib\
			php7-curl php7-mbstring php7-json php7-session mysql-client

ADD https://wordpress.org/latest.tar.gz .
RUN tar -xvf latest.tar.gz
RUN rm -f latest.tar.gz
RUN mv wordpress /etc/
RUN mkdir /run/nginx

COPY wp-config.php /etc/wordpress/
COPY launch-wordpress.sh /tmp/
COPY entrypoint.sh /tmp/
COPY wordpress.sql /tmp/
COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 5050
ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
