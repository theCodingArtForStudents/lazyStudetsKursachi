#ifndef FIELDDATA_H
#define FIELDDATA_H


class FieldData
{
public:
  FieldData(){}

  ~FieldData(){}

  template<typename T>
  FieldData& operator =(const T &value){ return *this; }




};

#endif // FIELDDATA_H
