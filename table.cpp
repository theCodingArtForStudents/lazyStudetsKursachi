#include "table.h"

#include <cstring>
//#include <ios>


Field *Table::create_field(const fieldType &type,
                           const std::string &name)
{
  Field *ftmp = new Field();

  if( type == INTEGER )
    {
      (*ftmp)[name] = new FieldType<int>();
    }
  else if( type == STRING )
    {
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

Table::Table(const fieldsTypesStack &fieldsTypes,
             const stringStack      &fieldsNames)
{
  _fieldsTypification = new fieldsTypesMap();
  _fieldsTitling = new fieldsNamesMap();
  while ( ! fieldsTypes.empty())
    {
      (*_fieldsTypification)[fieldsNames.top()] = fieldsTypes.top();
      (*_fieldsTitling)[fieldsTypes.top()] = fieldsNames.top();
    }
}

Table *Table::push_back(const Record &newRecord)
{
  if( _records == nullptr )
    _records = new Record();

  std::memcpy((*_records).back(), &newRecord.back(), sizeof(newRecord.back()));

  return this;
}

Table *Table::push_back(const fieldsDataStack &dataSet)
{
  if( _records == nullptr )
    _records = new Record();

  Field *tmp = (*_records).back();
  for(auto&& [name, value]: *tmp)
    {
      if( value == nullptr )
        *value = create_field((*_fieldsTypification)[name], name);

      *value = dataSet.top();
    }

  return this;
}
