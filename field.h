#ifndef FIELD_H
#define FIELD_H
#include <ios>

template<typename T>
class Field
{
protected:
  T* _data;
public:
  Field();
  ~Field();

  virtual Field<T>* operator =(Field<T>* data);
  virtual Field<T>* operator =(T* data);

};

#endif // FIELD_H
