FROM alpine

RUN apk --update add influxdb

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/influxd"]
