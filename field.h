#ifndef FIELD_H
#define FIELD_H

#include "fielddata.h"

#include <cstring>
#include <malloc.h>
#include<iostream>

template <typename T>
class FieldType : public FieldData
{
  T _data;
public:
//  FieldType();
  FieldType<T>() : FieldData ()
  {}

  FieldType(const FieldType<T>& other)
  {
    _data = other._data;
  }

  FieldType(T* value)
  {
    _data = value;
  }

  T& operator =(const FieldType<T>& obj);
  FieldType<T> &operator =(const T& value);

  friend std::ostream& operator <<(std::ostream& out, const FieldType<T>& obj);
  friend std::istream &operator >>(std::istream& in, const FieldType<T>& obj);

  ~FieldType()
  {}

};



#endif // FIELD_H

template<typename T>
std::ostream &operator <<(std::ostream& out, const FieldType<T> &obj)
{
  return out = obj._data;
}

template<typename T>
std::istream& operator >>(std::istream &in, const FieldType<T>& obj)
{
  obj._data = in;
  return in;
}

template <typename T>
T& FieldType<T>::operator =(const FieldType<T>& obj)
{
  return obj._data;
}

template<typename T>
FieldType<T> &FieldType<T>::operator =(const T &value)
{
  _data = value;
  return *this;
}
