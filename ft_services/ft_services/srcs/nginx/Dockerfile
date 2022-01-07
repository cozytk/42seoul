FROM alpine

COPY nginx.conf index.html setup.sh ./

RUN apk update
RUN apk add nginx openssl openssh
RUN	mv nginx.conf /etc/nginx
RUN mkdir -p /run/nginx
RUN mkdir /www && \
	mv index.html /www

RUN openssl req -new -newkey rsa:2048 -nodes -days 365 -x509 \
	-subj "/C=KR/ST=SEOUL/L=city/O=42/OU=cadet/CN=taekkim" \
	-keyout /etc/ssl/private/taekkim.key -out /etc/ssl/certs/taekkim.crt

RUN ssh-keygen -A && \
	adduser -D admin && \
	echo "admin:admin" | chpasswd

EXPOSE 22 80 443
ENTRYPOINT ["sh", "/setup.sh"]
