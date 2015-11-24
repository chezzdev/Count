In this section, we consider the simple installation of FastCGI-daemon in conjunction with [nginx] (http://nginx.org). Custom application for daemon will also be developed and tested.


## nginx intallation
Install nginx:

```
$ sudo apt-get install nginx
```

Configure nginx as a proxy for FastCGI-Daemon:

```
$ cat /etc/nginx/sites-enabled/fastcgi-daemon.conf

server {
  listen 80;

  location / {
    include fastcgi_params;
    fastcgi_param SCRIPT_FILENAME $fastcgi_script_name;
    fastcgi_pass unix:/tmp/fastcgi_daemon.sock;
  }
}
```

`fastcgi_pass` is the same socket, that FastCGI-daemon use.

Restart nginx:

```
$ service nginx restart
```

## FastCGI-daemon installation
Install FastCGI-daemon:

```
$ sudo apt-get install fastcgi-daemon2-init libfastcgi-daemon2-dev libfastcgi2-syslog
```

Next, we will develop a component `csimple` (`<component>`) in `csimple_module` (`<module>`), which we will compile as `libcsimple.so`. This component will be a handler (`<handler>`) of requests to `/csimple_res` resource. The component will be implemented by a class `SimpleClass` and registered as a `simple_factory`. 

Configuration file of FastCGI-daemon, which will handle this component looks as follows:

```
<?xml version="1.0"?>
<fastcgi xmlns:xi="http://www.w3.org/2001/XInclude">
<pools>
    <pool name="main" threads="1" queue="1"/>
</pools>
<handlers>
    <handler pool="main" url="/simple_res">
        <component name="csimple"/>
    </handler>
</handlers>
<components>
    <component name="csimple" type="csimple_module:simple_factory"/>
    <component name="daemon-logger" type="logger:logger">
       <level>INFO</level>
        <ident>fastcgi-test</ident>
    </component>
</components>
<modules>
    <module name="csimple_module" path="/fastcgi/csimple/libcsimple.so"/>
    <module name="logger" path="/usr/lib/fastcgi2/fastcgi2-syslog.so"/>
</modules>
<daemon>
    <logger component="daemon-logger"/>
    <endpoint>
        <backlog>128</backlog>
        <socket>/tmp/fastcgi_daemon.sock</socket>
        <threads>1</threads>
    </endpoint>
    <pidfile>/tmp/fastcgi_daemon.pid</pidfile>
    <monitor_port>20011</monitor_port>
</daemon>
</fastcgi>
```

`logger` module (`daemon-logger` component) is used for logging and should be included in all cases.
Save this file as `csimple.conf`.


## Component development
Our component will respond with header `Simple-Header` for all the requests.

```
#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>

class SimpleClass : virtual public fastcgi::Component, virtual public fastcgi::Handler {

public:
        SimpleClass(fastcgi::ComponentContext *context) :
                fastcgi::Component(context) {
        }
        virtual ~SimpleClass() {
        }

public:
        virtual void onLoad() {
        }
        virtual void onUnload() {
        }
        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context) {

                //Request handler code. The start point of the request processing.

                request->setHeader("Simple-Header", "Reply from csimple");
        }

};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("simple_factory", SimpleClass)
FCGIDAEMON_REGISTER_FACTORIES_END()
```

Save this code to file `SimpleClass.cpp` and compile it:

```
$ g++ SimpleClass.cpp -fPIC -lfastcgi-daemon2 -shared -o libcsimple.so
```

Put `libcsimple.so` into `/fastcgi/csimple`. Start FastCGI-Daemon:

```
$ fastcgi-daemon2 --config=csimple.conf
```

Test application:

```
$ curl -v "http://localhost/simple_res"

> GET /simple_res HTTP/1.1
> User-Agent: curl/7.22.0 (i686-pc-linux-gnu) libcurl/7.22.0 OpenSSL/1.0.1 zlib/1.2.3.4 libidn/1.23 librtmp/2.3
> Host: localhost
> Accept: */*
> 
< HTTP/1.1 200 OK
< Server: nginx/1.2.1
< Date: Wed, 28 Nov 2012 07:02:04 GMT
< Transfer-Encoding: chunked
< Connection: keep-alive
< Simple-Header: Reply from csimple
```

 We'll see "Simple-Header: Reply from csimple" in the server's response. That's all.
