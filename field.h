#ifndef FIELD_H
#define FIELD_H

//#include "fielddata.h"

#include <cstring>
#include <malloc.h>
#include<iostream>

#include <unordered_map>
#include <typeindex>


//typedef std::unordered_map<std::type_index, fieldType> typeInfo;

union anyType
{
  int _iData;
  std::string* _cData;
  size_t _countData;
  double _dData;

  anyType(){}
  anyType(const size_t& val){
    _countData = val;
  }
  anyType(const int& val){
    _iData = val;
  }
  anyType(const double& val){
    _dData = val;
  }
  anyType(const std::string &s)/*: _cData(*s)*/
  {
    _cData = new std::string(s);
  }
  ~anyType(){
    if( _cData != nullptr)
      delete _cData;
  }


//template <typename T>

  anyType& operator =(const anyType& obj);
  anyType &operator =(const int& value);
  anyType &operator =(const std::string& value);
  anyType &operator =(const double& value);
  anyType &operator =(const size_t& value);

  friend bool operator <(const anyType &left, const anyType &right);
  friend bool operator >(const anyType &left, const anyType &right);
  friend std::ostream& operator <<(std::ostream& out, const int& obj);
  friend std::ostream& operator <<(std::ostream& out, const std::string& obj);
  friend std::ostream& operator <<(std::ostream& out, const double& obj);
  friend std::ostream& operator <<(std::ostream& out, const size_t& obj);
  friend std::istream &operator >>(std::istream& in,  const std::string& obj);
  friend std::istream &operator >>(std::istream& in,  const double& obj     );
  friend std::istream &operator >>(std::istream& in,  const size_t& obj     );

  friend bool operator ==(const anyType& left, const anyType& right);
  friend bool operator ==(const anyType& left, const int& right);
  friend bool operator ==(const anyType& left, const std::string& right);
  friend bool operator ==(const anyType& left, const double&      right);
  friend bool operator ==(const anyType& left, const size_t&      right);
};

enum fieldType
{
  INTEGER,
  STRING,
  COUNTER,
  DOUBLE,

  UNDEFINEDTYPE
};


class FieldType// : public FieldData
{
private:
  anyType *_data = nullptr;
  fieldType _type;
public:
//  FieldType();
//  ~FieldType();

  FieldType();

  FieldType(const int& other);
  FieldType(const std::string& other);

  FieldType(const size_t& other);

  FieldType(const double& other);


  FieldType &operator =(const FieldType& obj);
  FieldType &operator =(const int& value);
  FieldType &operator =(const std::string& value);
  FieldType &operator =(const double& value);
  FieldType &operator =(const size_t& value);

  friend bool operator <(const FieldType &left, const FieldType &right);
  friend bool operator >(const FieldType &left, const FieldType &right);
  friend std::ostream& operator <<(std::ostream& out, const int& obj);
  friend std::ostream& operator <<(std::ostream& out, const std::string& obj);
  friend std::ostream& operator <<(std::ostream& out, const double& obj);
  friend std::ostream& operator <<(std::ostream& out, const size_t& obj);
  friend std::istream &operator >>(std::istream& in,  const std::string& obj);
  friend std::istream &operator >>(std::istream& in,  const double& obj     );
  friend std::istream &operator >>(std::istream& in,  const size_t& obj     );

  friend bool operator ==(const FieldType& left, const FieldType&   right);
  friend bool operator ==(const FieldType& left, const int&         right);
  friend bool operator ==(const FieldType& left, const std::string& right);
  friend bool operator ==(const FieldType& left, const double&      right);
  friend bool operator ==(const FieldType& left, const size_t&      right);

  std::string& toString();

  ~FieldType();

  fieldType type() const;
  anyType *data() const;

  anyType *data();
};

//bool operator ==(const FieldType& left, const FieldType&   right);
//bool operator ==(const FieldType& left, const int&         right);
//bool operator ==(const FieldType& left, const std::string& right);
//bool operator ==(const FieldType& left, const double&      right);
//bool operator ==(const FieldType& left, const size_t&      right);


#endif // FIELD_H

//std::ostream &operator <<(std::ostream& out, const FieldType &obj);

//std::istream& operator >>(std::istream &in, const FieldType& obj);

// FieldType::operator =(const FieldType& obj)
//{
//  return obj.data;
//}

////template<typename T>
//FieldType &FieldType::operator =(const T &value)
//{
//  _data = value;
//  return *this;
//}

//template<typename T>
/*
bool operator ==(const FieldType &left, const FieldType &right);*/

//*/
