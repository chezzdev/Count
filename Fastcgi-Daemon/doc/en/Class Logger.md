Operates with logging. Header - `fastcgi2/logger.h`.

Member functions:

|Function|Description|
|--------|-----------|
|[exiting](#-exiting)|Sends the DEBUG-level log info on exit from the function.|
|[entering](#-entering)|Sends the DEBUG-level log info on enter to the function.|
|[getLevel](#-getlevel)|Returns logging level (DEBUG, INFO, ERROR,EMERGENCY) of an application.|
|[setLevel](#-setlevel)|Sets the logging level for application.|
|[stringToLevel](#-stringtolevel)|Converts name of logging level into the  numeric identifier.|
|[levelToString](#-leveltostring)|Converts numeric identifier of logging level into its name.|
|[debug, info, error, emerg](#-ydebuginfoerroremerg)|Sends info of DEBUG, INFO, ERROR, EMERGENCY level respectively into the log.|
|[log](#-log)|Sends info of specified level into the log.|


## <a id="metodexiting"/> exiting
Sends DEBUG-level log info on exit from the function.

```
void exiting(const char *function)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|function|Function name.|

## <a id="metodentering"/> entering
Sends DEBUG-level log info on enter to the function.

```
void entering(const char *function)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|function|Function name.|

## <a id="metodgetlevel"/>getLevel
Returns logging level (DEBUG, INFO, ERROR,EMERGENCY) of an application.

```
Level getLevel() const
```

**Return value**

Numeric identifier of application log level. If this level is INFO then the messages of EMERGENCY, ERROR и INFO level will be logged, but DEBUG messages will not be logged.

## <a id="metodsetlevel"/>setLevel
Sets logging level for an application.

```
void setLevel(const Level level)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|level|Numeric identifier of logging level.|

## <a id="metodstringtolevel"/>stringToLevel
Converts name of logging level into numeric identifier.

```
static Level stringToLevel(const std::string &name)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|name|The name of logging level.|

**Return value**

A numeric identifier of logging level.

## <a id="metodleveltostring"/> levelToString
Converts numeric identifier of logging level into its name.

```
static std::string levelToString(const Level)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|level|A numeric identifier of logging level.|

**Return value**

The name of logging level.

## <a id="metodydebuginfoerroremerg"/>debug, info, error, emerg
Sends info of DEBUG, INFO, ERROR, EMERGENCY level respectively into the log.

```
virtual void debug(const char *format, ...)
virtual void info(const char *format, ...)
virtual void error(const char *format, ...)
virtual void emerg(const char *format, ...)
```

**Parameters**

|Parameter|Description|
|--------|--------|
|format|String format.|
|...|Format arguments.|

## <a id="metodlog"/> log
Sends info of specified level into the log.

```
virtual void log(const Level level, const char *format, va_list args) = 0
```

**Parameters**

|Parameter|Description|
|--------|--------|
|level|A numeric identifier of logging level.|
|format|A string format.|
|args|Format arguments.|
