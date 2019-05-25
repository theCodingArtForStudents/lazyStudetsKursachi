#ifndef FIELD_H
#define FIELD_H

#include "fielddata.h"

template <typename T>
class FieldType : public FieldData
{
  T* _data = nullptr;
public:
  FieldType();
  FieldType(const T& _value);
  FieldType<T> operator =(const T &value) override;

  ~FieldType() override;
};

#endif // FIELD_H
