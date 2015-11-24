Operates with request. It used to parse and modify the request and to create a response for it. Header - `fastcgi2/request.h`. 

Description of mentioned below CGI environment variables can be found in [RFC 3875](http://tools.ietf.org/html/rfc3875).

Member functions:

|Function|Description|
|-----|--------|
|[getServerPort](#-getserverport)|Get `SERVER_PORT` environment variable.|
|[getHost](#-gethost)|Get HTTP-header `Host`.|
|[getServerAddr](#-getserveraddr)|Get HTTP-server ip. `SERVER_ADDR` environment variable.|
|[getPathInfo](#-getpathinfo)|Get `PATH_INFO` environment variable.|
|[getPathTranslated](#-getpathtranslated)|Get `PATH_INFO` concatenated with `DOCUMENT_ROOT`. `PATH_TRANSLATED` environment variable.|
|[getScriptName](#-getscriptname)|Get `SCRIPT_NAME` environment variable. For example, `/requested_resource/`.|
|[getScriptFilename](#-getscriptfilename)|Get `SCRIPT_FILENAME` environment variable.|
|[getDocumentRoot](#-getdocumentroot)|Get `DOCUMENT_ROOT`environment variable. For example, `/etc/nginx/html`.|
|[getRemoteUser](#-getremoteuser)|Get `REMOTE_USER` environment variable.|
|[getRemoteAddr](#-getremoteaddr)|Get `REMOTE_ADDR` environment variable.|
|[getQueryString](#-getquerystring)|Get `QUERY_STRING` environment variable.|
|[getRequestMethod](#-getrequestmethod)|Get `REQUEST_METHOD` environment variable.|
|[getContentLength](#-getcontentlength)|Get size of the request body.|
|[getContentType](#-getcontenttype)|Get `Content-Type` HTTP-header.|
|[getURI](#-geturi)|Get 'SCRIPT_NAME' concatenated with request arguments. For example, `/requested_resource/?arg1=1&arg2=arg2`.|
|[getUrl](#-geturl)|Get URL. For example, `http://localhost/requested_resource/?arg1=1&arg2=arg2`.|
|[countArgs](#-countargs)|Get number of request arguments.|
|[hasArg](#-hasarg)|Check for argument existence.|
|[getArg](#-getarg)|Get argument value.|
|[argNames](#-argnames)|Get argument names.|
|[coutHeaders](#-coutheaders)|Get number of HTTP-headers.|
|[hasHeader](#-hasheader)|Check for header existence.|
|[getHeader](#-getheader)|Get header value.|
|[headerNames](#-headernames)|Get header names.|
|[countCookie](#-countcookie)|Count cookies.|
|[hasCookie](#-hascookie)|Check for cookie existence.|
|[getCookie](#-getcookie)|Get cookie value.|
|[cookieNames](#-cookienames)|Get cookie names.|
|[hasFile](#-hasfile)|Check for a file entity existence.|
|[remoteFiles](#-remotefiles)|Get file entity names.|
|[remoteFileName](#-remotefilename)|Get filename of file entity.|
|[remoteFileType](#-remotefiletype)|Get Content-Type of a file.|
|[remoteFile](#-remotefile)|Get file.|
|[isSecure](#-issecure)|Check the protocol (HTTP or HTTPS).|
|[requestBody](#-requestbody)|Get request body.|
|[setCookie](#-setcookie)|Set Set-Cookie header.|
|[setStatus](#-setstatus)|Set response status.|
|[sendError](#-senderror)|Set response status and send an error as HTML-page.|
|[setHeader](#-setheader)|Set header value.|
|[write](#-write)|Write to response body.|
|[outputHeader](#-outputheader)|Get response header.|
|[reset](#-reset)|Set HTTP-status of response to 200 and clear all of the request fields.|
|[attach](#-attach)|Attach data to the response body.|
|[isProcessed](#-isprocessed)|Check for request processing completion. The property is set by [markAsProcessed](#-markasprocessed).|
|[markAsProcessed](#-markasprocessed)|Set property of the request processing completion.|
|[redirectBack](#-redirectback)|Redirect request to `Referer` (HTTP-header).|
|[redirectToPath](#-redirecttopath)|Redirect request to the path.|
|[setContentType](#-setcontenttype)|Set Content-Type header.|
|[setContentEncoding](#-setcontentencoding)|Set Content-Encoding header.|
|[parse](#-parse)|Parse [DataBuffer](Class DataBuffer.md) as a request.|
|[serialize](#-serialize)|Convert request to a buffer.|
|[status](#-status)|Get response status.|


## <a id="metodgetserverport"/> getServerPort
Returns `SERVER_PORT` environment variable.

```
unsigned short getServerPort() const
```

**Return value**

The port number.

## <a id="metodgethost"/> getHost
Returns HTTP-header `Host`.

```
const std::string& getHost() const
```

**Return value**

A domain name or an IP-address.

## <a id="metodgetserveraddr"/> getServerAddr
Returns HTTP-server ip. `SERVER_ADDR` environment variable.

```
const std::string& getServerAddr() const
```

**Return value**

IP-address as a string.

## <a id="metodgetpathinfo"/> getPathInfo
Returns `PATH_INFO` environment variable.

```
const std::string& getPathInfo() const
```

**Return value**

`PATH_INFO` environment variable.

## <a id="metodgetpathtranslated"/> getPathTranslated
Returns `PATH_INFO` concatenated with `DOCUMENT_ROOT`. `PATH_TRANSLATED` environment variable.

```
const std::string& getPathTranslated() const
```

**Return value**

`PATH_TRANSLATED` environment variable.

## <a id="metodgetscriptname"/> getScriptName
Returns `SCRIPT_NAME` environment variable. For example, `/requested_resource/`.

```
const std::string& getScriptName() const
```

**Return value**

`SCRIPT_NAME` environment variable.

## <a id="metodgetscriptfilename"/> getScriptFilename
Returns `SCRIPT_FILENAME` environment variable.

```
const std::string& getScriptFilename() const
```

**Return value**

`SCRIPT_FILENAME` environment variable.

## <a id="metodgetdocumentroot"/> getDocumentRoot
Returns `DOCUMENT_ROOT`environment variable. For example, `/etc/nginx/html`.

```
const std::string& getDocumentRoot() const
```

**Return value**

`DOCUMENT_ROOT` environment variable.

## <a id="metodgetremoteuser"/> getRemoteUser
Returns `REMOTE_USER` environment variable.

```
const std::string& getRemoteUser() const
```

**Return value**

`REMOTE_USER` environment variable.

## <a id="metodgetremoteaddr"/> getRemoteAddr
Returns `REMOTE_ADDR` environment variable.

```
const std::string& getRemoteAddr() const
```

**Return value**

`REMOTE_ADDR` environment variable.

## <a id="metodgetquerystring"/> getQueryString
Returns `QUERY_STRING` environment variable.

```
const std::string& getQueryString() const
```

**Return value**

`QUERY_STRING` environment variable.

## <a id="metodgetrequestmethod"/> getRequestMethod
Returns `REQUEST_METHOD` environment variable.

```
const std::string& getRequestMethod() const
```

**Return value**

`REQUEST_METHOD` environment variable.

## <a id="metodgetcontentlength"/> getContentLength
Returns size of the request body.

```
std::streamsize getContentLength() const
```

**Return value**

Content length.

## <a id="metodgetcontenttype"/> getContentType
Returns `Content-Type` HTTP-header.

```
const std::string& getContentType() const
```

**Return value**

Content type.

## <a id="metodgeturi"/> getURI
Returns 'SCRIPT_NAME' concatenated with request arguments. For example, `/requested_resource/?arg1=1&arg2=arg2`.

```
std::string getURI() const
```

**Return value**

For example, `/requested_resource/?arg1=1&arg2=arg2`.

## <a id="metodgeturl"/> getUrl
Returns URL. For example, `http://localhost/requested_resource/?arg1=1&arg2=arg2`.

```
std::string getUrl() const
```

**Return value**

URL. For example, `http://localhost/requested_resource/?arg1=1&arg2=arg2`.

## <a id="metodcountargs"/> countArgs
Returns number of request arguments.

```
unsigned int countArgs() const
```

**Return value**

Number of arguments. If some argument has more then one value they counted separately. For example, in case of `arg1=1&arg2=arg2&arg1=2` function returns 3.

## <a id="metodhasarg"/> hasArg
Checks for an argument.

```
bool hasArg(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|An argument name. For example, `arg1`.|


**Return value** 

`true` if argument exists, `false` otherwise.

## <a id="metodgetarg"/> getArg
Returns argument value.

```
const std::string& getArg(const std::string &name) const
void getArg(const std::string &name, std::vector<std::string> &v) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|An argument name. For example `arg1`.|
|v|Output.|

**Return value**

An argument value.

If an argument has more then one value you should use version of function with vector `v`, otherwise you will get just the first value of an argument.

## <a id="metodargnames"/> argNames
Returns argument names.

```
void argNames(std::vector<std::string> &v)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|v|Output.|

## <a id="metodcoutheaders"/> coutHeaders
Returns number of http-headers.

```
unsigned int countHeaders() const
```

**Return value**

Number of headers.

## <a id="metodhasheader"/> hasHeader
Checks for a header existence.

```
bool hasHeader(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Header name. For example, `Content-Type`.|

**Return value**

`true`, if header exists, `false` otherwise.

## <a id="metodgetheader"/> getHeader
Returns header value.

```
const std::string& getHeader(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Header name. For example `Content-Type`.|

**Return value**

A header value.

## <a id="metodheadernames"/> headerNames
Returns header names.

```
void headerNames(std::vector<std::string> &v) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|v|Output.|


## <a id="metodcountcookie"/> countCookie
Returns number of cookies.

```
unsigned int countCookie() const
```

**Return value**

Number of cookies.

## <a id="metodhascookie"/> hasCookie
Checks for a cookie existance.

```
bool hasCookie(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Cookie name.|

**Return value**

`true`, if cookie exists, `false` otherwise.

## <a id="metodgetcookie"/> getCookie
Returns a cookie value.

```
const std::string& getCookie(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Cookie name.|

**Return value**

Cookie value.

## <a id="metodcookienames"/> cookieNames
Returns cookie names.

```
void cookieNames(std::vector<std::string> &v) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|v|Output.|

## <a id="metodhasfile"/> hasFile
Checks for a file entity existence.

```
bool hasFile(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Entity name.|

**Return value**

`true`, if file entity exists, `false` otherwise.

## <a id="metodremotefiles"/> remoteFiles
Returns file entity names.

```
void remoteFiles(std::vector<std::string> &v) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|v|Output.|

## <a id="metodremotefilename"/> remoteFileName
Returns filename of file entity.

```
const std::string& remoteFileName(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Entity name. For example `file1`.|

**Return value**

File name. For example, `draft.gif`.

## <a id="metodremotefiletype"/> remoteFileType
Returns Content-Type of a file.

```
const std::string& remoteFileType(const std::string &name) const;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|File entity name. For example `file1`.|

**Return value**

File type.

## <a id="metodremotefile"/> remoteFile
Returns file.

```
DataBuffer remoteFile(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|File entity name. For example `file1`.|

**Return value**

Content of a file.

## <a id="metodissecure"/> isSecure
Checks the protocol (HTTP or HTTPS).

```
bool isSecure() const
```

**Return value**

`true` if HTTPS used, `false` - otherwise.

## <a id="metodrequestbody"/> requestBody
Returns request body.

```
DataBuffer requestBody() const
```

**Return value**

Request body.

## <a id="metodsetcookie"/> setCookie
Sets `Set-Cookie` header.

```
void setCookie(const Cookie &cookie)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|cookie|Cookie.|

## <a id="metodsetstatus"/> setStatus
Sets the response status.

```
void setStatus(unsigned short status)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|status|Response HTTP-status.|


## <a id="metodsenderror"/> sendError
Sets the response status and send an error as HTML-page.

```
void sendError(unsigned short status)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|status|Response HTTP-status.|

## <a id="metodsetheader"/> setHeader
Sets header value.

```
void setHeader(const std::string &name, const std::string &value)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Header name.|
|value|Header value.|

## <a id="metodwrite"/> write
Writes to response body.

```
void write(std::streambuf *buf)
std::streamsize write(const char *buf, std::streamsize size)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|buf|Data.|
|size|Size of a data.|

**Return value**

Size of actually written data.

## <a id="metodoutputheader"/> outputHeader
Gets the response header.

```
std::string outputHeader(const std::string &name) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|Header name.|

**Return value**

Output header value.

## <a id="metodreset"/> reset
Sets HTTP-status of response to 200 and clear all of request fields.

```
void reset()
```

## <a id="metodattach"/> attach
Attaches data to the response body.

```
void attach(RequestIOStream *stream, char *env[])
```

**Parameters**

|Parameter|Description|
|--------|--------|
|stream|Data.|
|env|Environment.|


## <a id="metodisprocessed"/> isProcessed
Checks for request processing completion. The property is set by [markAsProcessed](#-markasprocessed).

```
bool isProcessed() const
```

**Return value**

`true` if processed.

## <a id="metodmarkasprocessed"/> markAsProcessed
Sets property of request processing completion.

```
void markAsProcessed()
```

## <a id="metodredirectback"/> redirectBack
Redirects request to `Referer` (HTTP-header).

```
void redirectBack()
```

## <a id="metodredirecttopath"/> redirectToPath
Redirects request to the path. Status is set to 302.

```
void redirectToPath(const std::string &path)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|path|Redirect address.|


## <a id="metodsetcontenttype"/> setContentType
Sets `Content-Type` header.

```
void setContentType(const std::string &type)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|type|Content type.|


## <a id="metodsetcontentencoding"/> setContentEncoding
Sets `Content-Encoding`.

```
void setContentEncoding(const std::string &encoding)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|encoding|Content encoding.|


## <a id="metodparse"/> parse
Parses [DataBuffer](Class DataBuffer.md) as a request.

```
void parse(DataBuffer buffer)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|buffer|HTTP-request, headers + body.|


## <a id="metodserialize"/> serialize
Converts request to a buffer.

```
void serialize(DataBuffer &buffer)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|buffer|Output.|

## <a id="metodstatus"/> status
Returns response status.

```
unsigned short status() const
```

**Return value**

Response status.
