{echo "POST / HTTP/1.1
Date: Fri, 31 Dec 1999 23:59:59 GMT
Content-Type: text/plain
Transfer-Encoding: chunked

1a
abcdefghijklmnopqrstuvwxyz";sleep 1;
} | telnet localhost 8081
{echo "10
1234567890123456
0";sleep 1;
} | telnet localhost 8081
