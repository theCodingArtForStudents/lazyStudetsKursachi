#ifndef FIELDDATA_H
#define FIELDDATA_H

#include <ios>

class FieldData
{
private:

public:
  FieldData(){}

  virtual ~FieldData();

  template<typename T>
  FieldData& operator =(const T &value){ return *this; }
  template<typename T>
  T& operator =(const FieldData &other){ return other; }

  template<typename T>
  friend bool operator ==(const T& left, const T& right);
  friend bool operator ==(const FieldData& left, const FieldData& right);
  friend std::ostream& operator <<(std::ostream& out, const FieldData& obj);
  friend std::istream &operator >>(std::istream& in, const FieldData& obj);


  virtual std::string& toString();


};

#endif // FIELDDATA_H
