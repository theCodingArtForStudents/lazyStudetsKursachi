#include "table.h"

#include <cstring>
//#include <ios>


Raw *Table::create_field(const fieldType &type,
                         const std::string &name)
{
  Raw *ftmp = new Raw();

  if( type == INTEGER )
    {
      (*ftmp)[name] = new FieldType<int>();
    }
  else if( type == STRING )
    {
//      FieldType<std::string> sFtmp;
      (*ftmp)[name] = new FieldType<std::string>();
    }
  else if ( type == COUNTER )
    {
      (*ftmp)[name] = new FieldType<size_t>();
    }
  else if ( type == DOUBLE )
    {

      (*ftmp)[name] = new FieldType<double>();
    }
  return ftmp;
}

Raw* Table::operator [](const size_t &index)
{
  return (*_records)[index];
}

fieldsTypesMap *Table::fieldsTypification() const
{
  return _fieldsTypification;
}

fieldsNamesMap *Table::fieldsTitling() const
{
  return _fieldsTitling;
}

bool Table::isEmpty()
{
  _isEmpty = _records == nullptr
           && _records->empty();
  return _isEmpty;
}

Table::Table(fieldsTypesStack &fieldsTypes,
             stringStack      &fieldsNames)
{
  _fieldsTypification = new fieldsTypesMap();
  _fieldsTitling = new fieldsNamesMap();
  while ( ! fieldsTypes.empty())
    {
      (*_fieldsTypification)[fieldsNames.top()] = fieldsTypes.top();
      (*_fieldsTitling)[fieldsTypes.top()] = fieldsNames.top();

      fieldsNames.pop();
      fieldsTypes.pop();
    }
}

Table::Table(Table *newTable)
{
  clear();
  _records = newTable->_records;
  _fieldsTitling = newTable->_fieldsTitling;
  _fieldsTypification = newTable->_fieldsTypification;

  isEmpty();
}

Table::~Table()
{
  clear();
}

Table *Table::push_back(const Record &newRecord)
{
  if( _records == nullptr )
    _records = new Record();

  std::memcpy((*_records).back(), &newRecord.back(), sizeof(newRecord.back()));

  return this;
}

Table *Table::push_back(fieldsDataStack &dataSet)
{
  if( _records == nullptr )
    _records = new Record();

//  Raw *tmp = (*_records).back();
  for(auto&& [name, value]: *(*_records).back())
    {
//      if( &value == nullptr )
        value = create_field((*_fieldsTypification)[name], name);

        value = dataSet.top();
    }

  return this;
}

Table *Table::erase()
{
  if( _records != nullptr )
    {
      for( auto raw : *_records )
        {
          if( raw != nullptr )
            raw->clear();
        }
      _records->clear();
    }
  return this;
}

Table *Table::clear()
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


