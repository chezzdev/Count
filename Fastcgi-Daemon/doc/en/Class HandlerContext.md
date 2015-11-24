Stores global parameters of custom request handler. Header `fastcgi2/handler.h`.

This is a storage of custom parameters, there is no data until `setParam` is called. You can call `getParam` only after corresponding `setParam`.

Member functions:

|Function|Description|
|--------|-----------|
|[getParam](#-getparam)|Returns parameter by the name.|
|[setParam](#-setparam)|Sets parameter by the name.|


## <a id="metodgetparam"/>getParam
Returns parameter by the name.

```
virtual boost::any getParam(const std::string &name) const = 0
```

**Parameters**

|Parameter|Description|
|---------|-----------|
|name|The parameter name.|

**Return value**

The parameter value.

## <a id="metodsetparam"/>setParam
Sets parameter by the name.

```
virtual void setParam(const std::string &name, const boost::any &value) = 0
```

**Parameters**

|Parameter|Decription|
|---------|----------|
|name|Parameter name.|
|value|Parameter value.|
