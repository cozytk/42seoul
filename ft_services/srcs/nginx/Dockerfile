FROM alpine:latest

RUN apk update
RUN apk add nginx
RUN apk add openssh
RUN apk add openssl

COPY default.conf /etc/nginx/conf.d/
COPY entrypoint.sh /tmp/
COPY ./ssl_key/jwon.crt /etc/nginx/ssl/
COPY ./ssl_key/jwon.key /etc/nginx/ssl/
COPY 42logo.png /var/lib/nginx/html/
COPY index.htm /var/lib/nginx/html/

EXPOSE 80 443 22
ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]