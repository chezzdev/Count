Provides context of a component. Header - `fastcgi2/component.h`.

Member functions:

|Function|Description|
|--------|-----------|
|[getConfig](#-getconfig)|Returns [Config](Class Config.md) which contains the configuration parameters of FastCGI-daemon.|
|[getComponentXPath](#-getcomponentxpath)|Returns XPath to the component description in the configuration file.|
|[findComponent](#-findcomponent)|Returns the pointer to the existing and loaded component.|

## <a id="metodgetconfig"/> getConfig
Returns [Config](Class Config.md) which contains the configuration parameters of FastCGI-daemon.

```
virtual const Config* getConfig() const = 0;
```

**Return value**

Pointer to [Config](Class Config.md).

## <a id="metodgetcomponentxpath"/> getComponentXPath
Returns XPath to the component description in the configuration file.

```
virtual std::string getComponentXPath() const = 0;
```

**Return value**

XPath. For example, `/fastcgi/components/component[1]`.

## <a id="metodfindcomponent"/> findComponent
Returns the pointer to the existing and loaded component.

```
template<typename T> T* findComponent(const std::string &name)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Name of the component.|

**Return value**

Pointer to the component class.
