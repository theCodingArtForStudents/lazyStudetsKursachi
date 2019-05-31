#include "tabel.h"

#include <cstring>
#include <iostream>


//#include <ios>


//Raw &Tabel::create_field(const fieldType &type,
//                         const std::string &name)
//{
//  Raw *ftmp = new Raw();

//  if( type == INTEGER )
//    {
//      (*ftmp)[name] = new FieldType<int>();
//    }
//  else if( type == STRING )
//    {
////      FieldType<std::string> sFtmp;
//      (*ftmp)[name] = new FieldType<std::string>();
//    }
//  else if ( type == COUNTER )
//    {
//      (*ftmp)[name] = new FieldType<size_t>();
//    }
//  else if ( type == DOUBLE )
//    {

//      (*ftmp)[name] = new FieldType<double>();
//    }
//  return *ftmp;
//}

Raw &Tabel::operator [](const size_t &index)
{
  return *_records[index];
}

fieldsTypesMap &Tabel::fieldsTypification() const
{
  return *_fieldsTypification;
}

fieldsNamesMap &Tabel::fieldsTitling()
{
  return *_fieldsTitling;
}

bool Tabel::isEmpty()
{
  _isEmpty = _records.empty();
  return _isEmpty;
}

Record Tabel::records() const
{
  return _records;
}

Tabel::Tabel(fieldsTypesStack &fieldsTypes,
             stringStack      &fieldsNames)
{
  _fieldsTypification = new fieldsTypesMap();
  _fieldsTitling = new fieldsNamesMap();
  create_fields(fieldsTypes, fieldsNames);
}

Tabel::Tabel(Tabel *newTable)
{
  clear();
  _records = newTable->_records;
  _fieldsTitling = newTable->_fieldsTitling;
  _fieldsTypification = newTable->_fieldsTypification;

  isEmpty();
}

Tabel::~Tabel()
{
  clear();
}

Tabel& Tabel::create_fields(fieldsTypesStack &fieldsTypes, stringStack &fieldsNames)
{
  if( _fieldsTypification != nullptr && _fieldsTitling != nullptr)
    {
      _fieldsTypification = new fieldsTypesMap();
      _fieldsTitling = new fieldsNamesMap();
    }
  if( fieldsNames.size() != fieldsTypes.size())
    {
      std::cerr << "[create_fields]: expected equal parameters numbers!" << std::endl;
      exit(1);
    }
  while ( ! fieldsTypes.empty())
    {
      (*_fieldsTypification)[fieldsNames.top()] = fieldsTypes.top();
      (*_fieldsTitling)[fieldsTypes.top()] = fieldsNames.top();

      fieldsNames.pop();
      fieldsTypes.pop();
    }
  return *this;
}


Tabel &Tabel::push_back(stringStack &fieldsNames, fieldsDataStack &dataSet)
{
  if( fieldsNames.size() != dataSet.size())
    {
      std::cerr << "[create_fields]: expected equal parameters numbers!" << std::endl;
      exit(1);
    }
  for(; ! fieldsNames.empty(); fieldsNames.pop())
    {
      auto *tmp = new Raw();
      auto str = fieldsNames.top();

      auto data = dataSet.top();
      (*tmp)[str] =  data;
      _records.push_back(tmp);
    }

  return *this;
}

Tabel &Tabel::erase()
{
  for( auto raw : _records )
    {
      if( raw != nullptr )
        raw->clear();
    }
  _records.clear();

  return *this;
}

Tabel &Tabel::clear()
{
  if( _fieldsTitling != nullptr )
    {
      _fieldsTitling->clear();
      delete _fieldsTitling;
    }
  if( _fieldsTypification != nullptr )
    {
      _fieldsTypification->clear();
      delete _fieldsTypification;
    }
  return erase();
}

auto Tabel::begin()
{
  return _records.begin();
}

auto Tabel::end()
{
  return _records.end();
}

size_t Tabel::count()
{
  return _records.size();
}

bool Tabel::configered()
{
  if( _fieldsTitling == nullptr && _fieldsTypification == nullptr )
    return false;
  return _fieldsTitling->empty() && _fieldsTypification->empty();
}


