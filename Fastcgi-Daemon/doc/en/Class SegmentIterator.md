Iterator for [DataBuffer](Class DataBuffer.md)
Header `fastcgi2/data_buffer.h`.

Operators:
```
SegmentIterator& operator++();
SegmentIterator operator++(int);
SegmentIterator& operator--();
SegmentIterator operator--(int);
```

Data can be accessed though the operators:

```
std::pair<char*, boost::uint64_t> operator*() const;
std::pair<char*, boost::uint64_t>* operator->() const;
```

The `first` member is a segment data, the `second` is a size of segment.
