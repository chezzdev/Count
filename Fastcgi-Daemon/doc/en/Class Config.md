Contains the configuration settings of the daemon. Header - `fastcgi2/config.h`.

Member functions:

|Function|Desription|
|--------|----------|
|[asInt](#-asint)|Returns the configuration parameter as an integer.|
|[asString](#-asstring)|Returns the configuration parameter as a string.|
|[subKeys](#-subkeys)|Returns XPath to the tags with the same name.|
|[filename](#-filename)|Returns a filename of configuration which daemon runs.|

## <a id="metodasint"/> asInt
Returns the configuration parameter as an integer.

```
virtual int asInt(const std::string &value) const = 0;
virtual int asInt(const std::string &value, int defval) const = 0;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|XPath to the required parameter. For example, `/fastcgi/daemon/monitor_port`.|
|defval|The default value, which is returned in case the requested value doesn't exist.|

**Return value**

The parameter as an interger.

## <a id="metodasstring"/> asString
Returns the configuration parameter as a string.

```
virtual std::string asString(const std::string &value) const = 0;
virtual std::string asString(const std::string &value, const std::string &defval) const = 0;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|XPath to the required parameter. For example, `/fastcgi/daemon/pidfile`.|
|defval|The default value, which is returned in case the requested value doesn't exist.|

**Return value**

The parameter as a string.

## <a id="metodsubkeys"/> subKeys
Returns XPath to tags with the same name.

```
virtual void subKeys(const std::string &value, std::vector<std::string> &v) const = 0;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|XPath to the configuration file tag. For example, `/fastcgi/components/component`.|
|v|Container for the result.|

**Return value**

A vector of the paths to the same named tags of the same branch of the configuration tree.

For example, `value=/fastcgi/components/component`, and we have a 3 components described in the configuration file. In this case the result will be:

```
/fastcgi/components/component[1]
/fastcgi/components/component[2]
/fastcgi/components/component[3]
```

## <a id="metodfilename"/> filename
Returns a filename of the configuration which daemon runs.

```
const std::string& filename() const;
```

**Return value**

A name of the configuration file.
