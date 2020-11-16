FROM alpine:latest

RUN apk update
RUN apk add mysql mysql-client

RUN mkdir -p /run/mysqld

COPY my.cnf /etc/mysql/
COPY mysql-init /tmp/
COPY entrypoint.sh /tmp/

# COPY ./ssl_key/ca-cert.pem /etc/mysql/certs/
# COPY ./ssl_key/server-cert.pem /etc/mysql/certs/
# COPY ./ssl_key/server-key.pem /etc/mysql/certs/

VOLUME ["/var/lib/mysql"]
EXPOSE 3306
ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
