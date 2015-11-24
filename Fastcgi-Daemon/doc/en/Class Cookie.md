Operates with cookies. Header - `fastcgi2/cookie.h`.

Member functions:

|Function|Description|
|-----|--------|
|[Cookie](#-konstruktorklassa)|Constructor.|
|[name](#-name)|Returns the name of a cookie.|
|[value](#-value)|Returns the value of a cookie.|
|[secure](#-secure)|Sets/returns the property of HTTPS usage.|
|[expires](#-expires)|Sets/returns a cookie expiration time.|
|[permanent](#-permanent)|Sets/returns the property of permanency.|
|[httpOnly](#-httponly)|Sets/returns the HTTP-only property.|
|[path](#-path)|Sets/returns a cookie path.|
|[domain](#-domain)|Sets a cookie domain.|
|[toString](#-tostring)|Returns a cookie string.|
|[urlEncode](#-urlencode)|Sets a property of urlencode. If `true`, then `toString` returns an urlencoded value.|

A custom component can get a request cookie and create new cookies with this class. When creating a new cookie its properties must be set by `secure, expires, permanent, httpOnly` etc. methods.
A cookie can be exported to the string with `toString` method.

## <a id="metodkonstruktorklassa"/> Constructor

```
Cookie(const std::string &name, const std::string &value);
Cookie(const Cookie &cookie);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|A cookie name.|
|value|A cookie value.|
|cookie|A cookie.|

## <a id="metodname"/> name
Returns a cookie name.

```
const std::string& name() const;
```

**Return value**

A cookie name.

## <a id="metodvalue"/> value
Returns a cookie value.

```
const std::string& value() const;
```
**Return value**

A cookie value.

## <a id="metodsecure"/> secure
Sets/returns the property of HTTPS usage.

```
bool secure() const;
void secure(bool value);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|`true`, if HTTPS needed.|

**Return value**

The property of HTTPS usage.

## <a id="metodexpires"/> expires
Sets/returns a cookie expiration time.

```
time_t expires() const;
void expires(time_t value);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|A cookie expiration UNIX-time.|

**Return value**

A cookie expiration UNIX-time.

## <a id="metodpermanent"/> permanent
Sets/returns the property of permanency.

```
void permanent(bool value);
bool permanent() const;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|`true`, if cookie should be permanent.|

**Return value**

`true`, if cookie is permanent.

## <a id="metodhttponly"/> httpOnly
Sets/returns the HTTP-only property.

```
void httpOnly(bool value);
bool httpOnly() const;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|`true` if HTTP-only needed.|

**Return value**

The HTTP-only property.

## <a id="metodpath"/> path
Sets/returns a cookie path.

```
const std::string& path() const;
void path(const std::string &value);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|A cookie path.|

**Return value**

A cookie path.

## <a id="metoddomain"/> domain
Sets a cookie domain.

```
const std::string& domain() const;
void domain(const std::string &value);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|A cookie domain.|

**Return value**

A cookie domain.

## <a id="metodtostring"/> toString
Returns a cookie string.

```
std::string toString() const;
```

**Return value**

A cookie. For example, `coname=coval; domain=yandex.ru; HttpOnly`.

## <a id="metodurlencode"/> urlEncode
Sets the property of urlencode. If `true`, then `toString` returns an urlencoded value.

```
void urlEncode(bool value);
```

**Parameters**

|Parameter|Description|
|--------|--------|
|value|An urlendode property.|
