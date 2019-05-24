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
  erase_data();
  _data = data;
}

template<typename T>
Field<T>::Field(const T &data)
{
  erase_data();
  copy_data(data);
}

template<typename T>
Field<T>::~Field()
{
  erase_data();
}

template<typename T>
Field<T> *Field<T>::operator =(T *data)
{
  if( data != nullptr )
    {
      _data = data;
    }
  return this;
}

template<typename T>
Field<T> *Field<T>::operator =(const T &data)
{
  erase_data();
  copy_data(data);

  return this;
}

template<typename T>
void Field<T>::erase_data()
{
  if( _data != nullptr )
    delete[] _data;
}

template<typename T>
void Field<T>::copy_data(const T &data)
{
  _data = new T();
  std::memcpy(_data, data, sizeof(data));
}

