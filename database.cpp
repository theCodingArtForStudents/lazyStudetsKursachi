#include "database.h"

#include <iostream>

bool DataBase::isEmpty()
{
  _isEmpty = _tables.empty() ;
  return _isEmpty;
}

bool DataBase::clear()
{
  for(auto&& [key, val] : _tables)
    {
      val->clear();
    }
  _tables.clear();

  return isEmpty();
}

DataBase::DataBase()
{
}

DataBase::DataBase(stringStack &tabelsNames,
                   Maped_fieldsTypesStack &tabels_fieldsTypes,
                   Maped_fieldsNamesStack &tabels_fieldsNames)
{
  for(; ! tabelsNames.empty(); tabelsNames.pop() )
    {
      std::string tName = tabelsNames.top();
      if( ! ( tabels_fieldsTypes[tName].empty() && tabels_fieldsTypes.empty() ) )
        {
          auto tFtype = tabels_fieldsTypes[tName];
          auto tFName = tabels_fieldsNames[tName];
          _tables[tabelsNames.top()]->create_fields(tFtype, tFName);
        }
      else
          std::cerr << "[DataBase]: Types or Names set are empty!" << std::endl;
    }
}

bool DataBase::insert(const std::string &tabelName,
                      stringStack &fieldsNames,
                      fieldsDataStack &fieldsData)
{
  _tables[tabelName]->push_back(fieldsNames, fieldsData);
  return _tables[tabelName]->isEmpty();
}

Maped_fieldsDataStack &DataBase::select(const std::string &tabelName,
                                        stringStack &fieldsNames)
{
  Maped_fieldsDataStack* result = new Maped_fieldsDataStack();
  
  for(; ! fieldsNames.empty(); fieldsNames.pop() )
    {
      size_t i = 0;
      for( auto&& [key, value] : (*_tables[tabelName])[i])
      {
        i++;
        (*result)[(fieldsNames.top())].push(value);
      } 
    }
  
  return *result;
}

Maped_fieldsDataStack &DataBase::select(const std::string &tabelName,
                                        const std::string &fieldName)
{
  Maped_fieldsDataStack* result = new Maped_fieldsDataStack();

  if( fieldName == "*" )
    {
      auto recs = (_tables[tabelName])->records();
      for(auto&& [key, value] : *recs[0])
        {
          for (auto raw : recs)
            {
              (*result)[key].push( value );
            }
        }
    }
  else{
      stringStack *stk = new stringStack;
      stk->push(fieldName);
      *result = select(tabelName, *stk);
  }
  return *result;
}

bool DataBase::update(const std::string &tabelName,
                      stringStack &fieldsNames,
                      fieldsDataStack &oldData,
                      fieldsDataStack &newData)
{
  auto recs = _tables[tabelName]->records();

  if( fieldsNames.empty()
      || oldData.empty()
      || newData.empty()
      )
    {
      std::cerr << "[DataBase::update]: some parameter is empty!" << std::endl;
      return false;
    }

  bool updateFlag = false;
  for(size_t i = 0; i < recs.size(); i++)
    {
      auto rec = *recs[i];

      for(auto field = fieldsNames.top(); ! fieldsNames.empty(); fieldsNames.pop())
        {
          if( rec[field].data() == oldData.top().data() )
            {
              auto data = newData.top();
              switch (int(data.type())) {
                  case INTEGER:
                      rec[field] = (data.data()->_iData);
                      break;
                  case STRING:
                      rec[field] = *(data.data()->_cData);
                      break;
                  case DOUBLE:
                      rec[field] = (data.data()->_dData);
                      break;
                  case COUNTER:
                      rec[field] = (data.data()->_countData);

                      break;
                  }
//              rec[field] = newData.top();
              updateFlag |= true;
            }
          else
            {
              updateFlag |= false;
            }
        }

    }
  return updateFlag;
}



