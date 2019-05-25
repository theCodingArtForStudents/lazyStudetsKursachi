#include "field.h"
#include <cstring>

template<typename T>
FieldType<T>::FieldType()
{
  if( _data == nullptr )
    _data = new T();
}

template<typename T>
FieldType<T>::FieldType(const T &value)
{
  FieldType();
  std::memcpy(_data, value, sizeof(value));
}

template<typename T>
FieldType<T> FieldType<T>::operator =(const T &value)
{
  if( _data != nullptr )
    ~FieldType();
  FieldType();
  _data = value;
}

template<typename T>
FieldType<T>::~FieldType()
{
 if(_data != nullptr)
   delete[] _data;
}

