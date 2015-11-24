Abstract class, that should be inherited by a custom components. Header - `fastcgi2/component.h`.

Member functions:

|Function|Description|
|--------|-----------|
|[onLoad](#-onload)|Callback method, called at component load.|
|[onUnload](#-onunload)|Callback method, called at component unload.|
|[context](#-context)|Returns a component context.|

## <a id="methodonload"/> onLoad
Callback method, called at component load.

```
virtual void onLoad() = 0;
```

## <a id="methodonunload"/> onUnload
Callback method, called at component unload.

```
virtual void onUnload() = 0;
```

## <a id="methodcontext"/> context
Returns a component context.

```
ComponentContext* context();
const ComponentContext* context() const;
```

**Return value**

A component context.
