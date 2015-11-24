Abstract class, mandatory for inheritance by a custom component. It is the base of a custom request handler. Header - `fastcgi2/handler.h`.

Member functions:

|Function|Description|
|--------|-----------|
|[onThreadStart](#-onthreadstart)|Callback function.|
|[handleRequest](#-handlerequest)|Start point of the request processing.|

## <a id="metodonthreadstart"/>Метод onThreadStart
Callback function.

```
virtual void onThreadStart()
```

## <a id="metodhandlerequest"/>Метод handleRequest
Start point of the request processing. It called by daemon on incoming request.

```
virtual void handleRequest(Request *req, HandlerContext *context) = 0
```

**Parameters**

|Parameter|Description|
|---------|-----------|
|req|A pointer to [Request](Class Request), which contains all the request info and provides functions to operate with it.|
|context|Pointer to [HandlerContext](Class HandlerContext.md).|