FROM alpine:latest

RUN apk update && apk add influxdb

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/influxd"]