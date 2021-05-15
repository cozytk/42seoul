# webserv
`C++ 98`

RFC 7230 to 7235 (http 1.1) 번역 ▼

https://roka88.dev/105

https://giju.gitbook.io/rfc7231/



#### 구현해야 하는 HEADER
```
◦ Accept-Charsets
◦ Accept-Language
◦ Allow
◦ Authorization
◦ Content-Language
◦ Content-Length
◦ Content-Location
◦ Content-Type
◦ Date
◦ Host
◦ Last-Modified
◦ Location
◦ Referer
◦ Retry-After
◦ Server
◦ Transfer-Encoding
◦ User-Agent
◦ WWW-Authenticate
```



#### Mozilla에 정리된 헤더 ▼

https://developer.mozilla.org/ko/docs/Web/HTTP/Headers



#### CGI ▼

개념
http://www.mnuwer.dbasedeveloper.co.uk/dlearn/web/session01.htm

개념 및 아파치에서의 CGI

https://httpd.apache.org/docs/trunk/ko/howto/cgi.html

Perl-CGI 동적 페이지 구성

https://www.geeksforgeeks.org/perl-cgi-programming/

CGI 헤더 ?

https://docs.oracle.com/cd/E21043_01/doc.1111/e10726/toc.htm



#### Worker 개념

nginx 에서의 Worker

https://kmseop.tistory.com/217

https://velog.io/@wijihoon123/Nginx%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80

이벤트 기반 처리 (멀티 쓰레드 Worker)

https://velog.io/@limprove89/%EC%9D%B4%EB%B2%A4%ED%8A%B8-%EA%B8%B0%EB%B0%98-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-%EC%93%B0%EB%A0%88%EB%93%9C









## 보너스
₩₩₩
Your program can have workers define as:
◦ a worker can be either processes or threads (and use fork for them)
◦ a worker should not be spawn for each client and must able to take care of an
infinite number of requests
◦ workers are not mandatory
◦ you can use fork, wait, waitpid, wait3, wait4, dup, dup2, pipe or pthread_create,
pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy,
pthread_mutex_lock, pthread_mutex_unlock
• Add any number of the following in the configuration file:
◦ choose a number of worker (if your program implements workers)
₩₩₩
Worker 구현에 관한
