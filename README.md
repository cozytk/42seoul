# Server -> Request (Reqeust 진입점)
### 일반적인 RECV

`./srcs/server/Server.cpp: line 150`
```
this->_request[socket]->_buffer 에 header, body 전부 받아서 저장되어 있음
```




### chunked RECV

`./srcs/server/Server.cpp: line 158`
```
this->_request[socket]->_buffer 에 header, body 전부 받아서 저장되어 있음
```

> this->_request[socket]->_buffer 예시 ▼
>```
>POST / HTTP/1.1
>Host: 127.0.0.1:8081
>User-Agent: Go-http-client/1.1
>Transfer-Encoding: chunked
>Content-Type: test/file
>Accept-Encoding: gzip
>
>5
>hello
>6
> world
>0
>```




# base64
RFC -> https://datatracker.ietf.org/doc/html/rfc2045

`usage ▼`
```
std::string ft::base64::encode(std::string const &str);
std::string ft::base64::decode(std::string const &str);
```
