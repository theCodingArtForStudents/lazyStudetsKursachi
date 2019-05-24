#include "field.h"
#include <cstring> // for memcpy

template<typename T>
Field<T>::Field()
{
  _data = new T();
}

template<typename T>
Field<T>::Field(T *data)
{
  _data = data;
}

template<typename T>
Field<T>::Field(const T &data)
{
  _data = new T();
  std::memcpy(_data, data, sizeof(data));
}
