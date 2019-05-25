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

Table::~Table()
{
  if( _records != nullptr ){
      for( auto rec : (*_records)){
          if( rec != nullptr )
            rec->clear();
          delete rec;
        }
      delete [] _records;
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

  Raw *tmp = (*_records).back();
  for(auto&& [name, value]: *tmp)
    {
      if( value == nullptr )
        *value = create_field((*_fieldsTypification)[name], name);

      *value = dataSet.top();
    }

  return this;
}
