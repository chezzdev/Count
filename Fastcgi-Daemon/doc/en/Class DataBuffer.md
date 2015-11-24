Operates with a data. Header - `fastcgi2/data_buffer.h`.

Member functions:

|Function|Description|
|-----|--------|
|[DataBuffer](#konstruktorklassa)|Constructor.|
|[at](#-at)|Returns a symbol.|
|[empty](#-empty)|Checks whether the buffer is empty.|
|[size](#-size)|Returns size of a buffer in bytes.|
|[resize](#-resize)|Changes size of a buffer.|
|[begin](#-begin)|Returns the first segment of a buffer.|
|[end](#-end)|Returns the end of a buffer.|
|[trim](#-trim)|Trims a buffer.|
|[trimn](#-trimn)|Gets a fragment from a buffer.|
|[split](#-split)|Splits a buffer in two.|
|[startsWith](#-startswith)|Compares start of a buffer and a string.|
|[startsWithCI](#-startswithci)|Compares start of a buffer and a string case insensitive.|
|[endsWith](#-endswith)|Compares the end of a buffer and a string.|
|[endsWithCI](#-endswithci)|Compares the end of a buffer and a string case insensitive.|
|[toString](#-tostring)|Returns buffer as a sring.|
|[read](#-read)|Reads data from a buffer.|
|[write](#-write)|Writes data to a buffer.|
|[beginIndex](#-beginindex)|Returns number of the first byte in a buffer.|
|[endIndex](#-endindex)|Returns number of the last byte in a buffer.|


## <a id="konstruktorklassa"/>Constructor

```
DataBuffer();
DataBuffer(DataBuffer buffer, boost::uint64_t begin, boost::uint64_t end)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|buffer|Buffer.|
|begin|Start position. Count starts from 0.|
|end|The end position.|

## <a id="metodat"/>at
Returns a symbol.

```
char at(boost::uint64_t pos) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|pos|Position.|

**Return value**

Symbol at the selected position.

## <a id="metodempty"/>empty
Checks whether the buffer is empty.

```
bool empty() const
```

**Return value**

`true` if a buffer empty or does not exists.

## <a id="metodsize"/>size
Returns size of a buffer in bytes.

```
boost::uint64_t size() const
```

**Return value**

Size of a buffer in bytes.

## <a id="metodresize"/>resize
Changes size of a buffer.

```
void resize(boost::uint64_t size)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|size|New size of a buffer.|


## <a id="metodbegin"/>begin
Returns the first segment of a buffer.

```
SegmentIterator begin() const
```

**Return value**
SegmentIterator with the first segment of a buffer.

## <a id="metodend"/>end
Returns the end of a buffer.

```
SegmentIterator end() const
```

**Return value**

SegmentIterator referring to the past-the-end element of a segmented buffer.

## <a id="metodtrim"/>trim
Trims a buffer.

```
DataBuffer trim() const
```

**Return value**

Trimmed DataBuffer.

## <a id="metodtrimn"/>trimn
Returns fragment from a buffer.

```
DataBuffer trimn(boost::uint64_t b, boost::uint64_t e) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|b|Start position.|
|e|The end position.|

**Return value**

DataBuffer with the selected data.

## <a id="metodsplit"/>split
Splits a buffer in two.

```
bool split(const std::string &delim, DataBuffer &first, DataBuffer &second) const;
bool split(char delim, DataBuffer &first, DataBuffer &second) const;
```

**Parameters**

|Parameter|Description|
|--------|--------|
|delim|Symbol or a string delimiter.|
|first|A Buffer for the first part of data.|
|second|A Buffer for the second part of data.|

**Return value**

`true`, if success.

## <a id="metodstartswith"/>startsWith
Compares start of a buffer and a string.

```
bool startsWith(const std::string &data) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|data|String for comparison.|

**Return value**

`true` if a string matched with start of a buffer.

## <a id="metodstartswithci"/>startsWithCI
Compares start of a buffer and a string case insensitive.

```
bool startsWithCI(const std::string &data) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|data|String for comparison.|

**Return value**

`true` if a string matched with start of a buffer.

## <a id="metodendswith"/>endsWith
Compares end of a buffer and a string.

```
bool endsWith(const std::string &data) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|data|String for comparison.|

**Return value**

`true` if a string matched with the end of buffer.

## <a id="metodendswithci"/>endsWithCI
Compares end of a buffer and a string case insensitive.

```
bool endsWithCI(const std::string &data) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|data|String for comparison.|

**Return value**
`true` if a string matched with the end of buffer.

## <a id="metodtostring"/>toString
Returns buffer as a string.

```
void toString(std::string &str) const
```

**Parameters**

|Parameter|Description|
|--------|--------|
|str|String to save the result.|


## <a id="metodread"/>read
Reads data from a buffer.

```
boost::uint64_t read(boost::uint64_t pos, char *data, boost::uint64_t len)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|pos|Buffer position.|
|data|Variable to store the result.|
|len|Length of the required data.|

**Return value**

Number of bytes read.

## <a id="metodwrite"/>write
Writes data to buffer.

```
boost::uint64_t write(boost::uint64_t pos, const char *data, boost::uint64_t len)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|pos|Buffer position.|
|data|Data to write.|
|len|Size of the data.|

**Return value**

Number of bytes actually written.

## <a id="metodbeginindex"/>beginIndex
Returns number of the first byte in buffer.

```
boost::uint64_t beginIndex() const
```

**Return value**

Number of the first byte.

## <a id="metodendindex"/>endIndex
Returns number of the last byte in a buffer.

```
boost::uint64_t endIndex() const
```

**Return value**

Number of the last byte.
