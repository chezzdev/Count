## Configuration objects
Logically daemon consists of multiple thread pools, one of which is a pool of sockets, and the remaining pools are run the request handlers.

Socket pool is responsible for receiving data from the HTTP-server and forwarding the request to the appropriate handler. Its configuration is set in the `<daemon>` section of configuration file.

Handlers are implemented as shared objects (`<module>`) and may contain several components (`<component>`). Each component can run in any worker pool (`<handler>`). Socket pool pass requests into the handlers.

Daemon can have many worker pools and they are separately configurable in `<pools>` section. Each pool has configurable maximum amount of threads and maximum size of an entrance queue. Administrator can manage pool priority using it.

## Configuration file
The configuration is stored in XML-file like that:

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

Tags:

* pools - worker pools definition. Contains attributes:
 * `name` - pool name. Defined by administrator;
 * `threads` - maximum number of threads in pool;
 * `queue` - size of queue of incoming requests.
* handlers - consists of `handler` tags.
 * handler - associate the user's request and a handler component. Handler can be configured for a specific port, domain/host or url. Contains attributes:
  * url - resource name. For example, `url="/some_resource"`; 
  * host - `Host` header of the request; 
  * port - nginx port;
  * address - nginx bind address from its configuration file (one from `listen`);
  * pool - pool name. The only required attribute, remaining attributes can be specified arbitrarily. 
  
  Can contain `param` (there may be several) and `component` tags.
     * param - defines requred request parameter. Attribute `name` - name of the parameter.
     * component - component which will handle request. Attribute `name` - name of the component.
* components - contains `component` tags.
 * component - component definition. Can contain any tags required by the developer of component. Contains attributes: 
     * `name` - component name;
     * `type` - <module>:<component factory>. Component factory name provided by developer.
* modules - contains `module` tags.
 * module - definition of module with FastCGI-application. Contains attributes:
     * name - module name. Defined by administrator;
     * path - path to the shared object with the custom application.
* daemon - definition of common daemon parameters and parameters of a socket pool. Contains`logger`, `endpoint`, `pidfile`, `monitor_port` tags.
 * logger - logging component. Attribute `component` - a component name.
 * endpoint - a socket pool configuration. Contains tags: 
     * backlog - size of queue of incoming connections from nginx. Extra connections will be dropped;
     * socket - path to the socket;
     * threads - maximum number of threads in a pool.
 * pidfile - path to a pid-file.
 * monitor_port - monitoring port of a daemon. If you want to check daemon state you should `netcat` to this port.

Logging configuration.
Component `daemon-logger` is used for logging into syslog. To use it, configure component with tags `level` and `ident`, setting log level and application id for syslog.

## Operability test
To make sure that the daemon is running, use the command:

```
$ echo i | netcat localhost port
```

`port` should have the same value, that contained in `<daemon><monitor_port>value</monitor_port></daemon>` of configuration file.

You will see the next XML as a response:

```
<fastcgi-daemon>
    <status>running</status>
    <pools>
        <endpoint_pools>
            <endpoint socket="/tmp/fastcgi_daemon.sock" threads="1" busy="0"/>
        </endpoint_pools>
        <pool name="main" threads="1" busy="0" queue="1" current_queue="0" all_tasks="0" exception_tasks="0"/>
    </pools>
</fastcgi-daemon>
```