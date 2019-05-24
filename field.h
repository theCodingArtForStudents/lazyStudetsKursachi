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
  Field(T* data);
  Field(const T& data);
  ~Field();

  virtual Field<T>* operator =(T* data);
  virtual Field<T>* operator =(const T& data);

private:
  void erase_data();
  void copy_data(const T& data);
};

#endif // FIELD_H
