Applications (custom components) for FastCGI-Daemon are the shared objects (so). You should compile `libfastcgi-daemon2.so` and use headers in `include/fastcgi2` for development.

API contains the namespace `fastcgi`, with the classes:

|**Class**|**Description**|
|---------|------------|
|[Component](Class Component.md)|Abstract class, mandatory for inheritance by a custom component. It is the base of a custom component.|
|[ComponentContext](Class ComponentContext.md)|Keeps the context of a custom component.|
|[Config](Class Config.md)|Contains configuration settings of daemon.|
|[Cookie](Class Cookie.md)|Operates with cookies.|
|[DataBuffer](Class DataBuffer.md)|Operates with data.|
|[SegmentIterator](Class SegmentIterator.md)|Iterator for the segmented `DataBuffer`.|
|[Handler](Class Handler.md)|Abstract class, mandatory for inheritance by a custom component. It is the base of a custom request handler.|
|[HandlerContext](Class HandlerContext.md)|Stores global parameters of a custom request handler.|
|[Logger](Class Logger.md)|Operates with logging.|
|[Request](Class Request.md)|Operates with a request. It used to parse and modify request and to create a response for it.|

Custom component must inherit from `Component` and `Handler`. Methods `onLoad()`, `onUnload()` and `handleRequest(...)` should be defined. Component should use macros defined in `ComponentFactory.h` in order to provide its functionality to daemon.

For example, user defines 2 components in its module (.so):

```
class ExampleComponent1 : virtual public fastcgi::Component, virtual public fastcgi::Handler{...}
class ExampleComponent2 : virtual public fastcgi::Component, virtual public fastcgi::Handler{...}
```

They should be registered as follows:

```
FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("factory1", ExampleComponent1)
FCGIDAEMON_ADD_DEFAULT_FACTORY("factory2", ExampleComponent2)
FCGIDAEMON_REGISTER_FACTORIES_END()
```

To use syslog, custom component should get `daemon-logger` using the `findComponent` method of [ComponentContext](Class ComponentContext.md) class. Then use methods of [Logger](Class Logger.md) class as follows:

```
fastcgi::ComponentContext *cntx = context();
fastcgi::Logger *log = cntx->findComponent<fastcgi::Logger>("daemon-logger");
log->info("some useful info");
```
