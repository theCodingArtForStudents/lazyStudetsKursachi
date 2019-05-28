#ifndef FIELD_H
#define FIELD_H

#include "fielddata.h"

#include <cstring>
#include <malloc.h>

template <typename T>
class FieldType : public FieldData
{
  T _data;
public:
//  FieldType();
  FieldType<T>() : FieldData ()
  {

  }
  template <typename U>
  FieldType(const U& value)
  {
    _data = value;
  }
  FieldType(T* value)
  {
    _data = value;
  }

  FieldType<T>* operator =(const T &value)
  {
    if( _data != nullptr )
      ~FieldType();
    FieldType();

    *_data = value;
        // = value;

    return this;
  }

  ~FieldType()
  {

  }
};

#endif // FIELD_H
