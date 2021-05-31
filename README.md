# Config

### Rule
괄호 { } 는 반드시 닫혀야 합니다.
```
block_name val1 val2 {
  ...
}
```

블록 선언 (괄호)이 아닌 모든 변수 선언은 ;로 끝나야 합니다.
```
val_name value1 value2 value3;
```

### Usage
Config 클래스는 아래와 같이 선언되고 사용됩니다.


`sample.conf`
```
42test {
  sample 1 2 3 4 {
    root html java ruby_on_rails "s p a c e";
  }
}

user
{
  u {
    a {
      b value1 {
      }
    }
  }
}
```

`code`
```
#include "Config.hpp"
...

Config config;
config.file("./sample.conf"); // sample.conf 파일을 분석하여 트리로 구조화

std::cout << (*config("42test", 0)("sample", 0))[0] << std::endl;
std::cout << (*config("42test", 0)("sample", 0)("root", 0))[2] << std::endl;
```

출력)
```
1
ruby_on_rails
```

설명
```
블록에 접근할 때 사용합니다.
node& operator()(std::string const &name, int index = 0);

해당 블록이 현재 스코프에 몇 개 존재하는 지 반환합니다.
int size(std::string name);

변수값을 반환합니다. 변수값은 하나가 아닐 수 있으므로 벡터 형태로 반환하게 됩니다.
std::vector<std::string> &operator*();

ex)
config("a") 는 config("a", 0)와 같은 위치의 블록을 참조합니다

config("42test")는 아래 블록을 참조하게 됩니다.

42test {
  sample 1 2 3 4 {
    root html java ruby_on_rails "s p a c e"
  }
}

config("42test")("sample") 는 아래 블록을 참조하게 됩니다.
sample 1 2 3 4 {
  root html java ruby_on_rails "s p a c e"
}

*config("42test")("sample") 는 벡터를 반환하며 ["1", "2", "3", "4"] 의 형태를 가지게 됩니다.
*config("42test")("sample")("root") 는 벡터를 반환하며 ["html", "java", "ruby_on_rails", "s p a c e"] 의 형태를 가지게 됩니다.

config.size("42test") 는 현재 스코프 (제일 바깥)에 42test 블록이 하나 존재하므로 1을 반환합니다.

config("42test").size("sample") 은 현재 스코드 (42test { ~ }) 에 sample 블록이 하나 존재하므로 1을 반환합니다.
```


# Auto Index
`code`
```
#include "AutoIndex.hpp"

...

AutoIndex autoindex; // 사전에 필요한 자원을 생성과 동시에 준비합니다. 따라서 AutoIndex를 매 연결마다 만드는 것은 추천하지 않습니다.

autoindex.path("/srcs/"); // path 를 받아 파일 리스트를 준비합니다.
autoindex.make(); // std::string 을 반환하며 오토인덱스 페이지 (html)를 반환합니다.
```

아래는 결과입니다.




# Log

# CGI
`각 환경변수는 request에서 들어온 정보를 바탕으로 정리됨`



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
