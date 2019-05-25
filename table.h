#ifndef TABLE_H
#define TABLE_H

#include <variant>
#include <map>
#include <stack>
#include <list>
#include <vector>

#include "field.h"

enum fieldType
{
  INTEGER,
  STRING,
  COUNTER,
  DOUBLE
};

//typedef  std::variant<int, std::string, size_t, double> FieldData;
typedef std::map<std::string, FieldData*> Field;

typedef std::vector<Field *> Record;

typedef std::map<std::string, fieldType>  fieldsTypesMap;
typedef std::map<fieldType, std::string>  fieldsNamesMap;
typedef std::stack<fieldType> fieldsTypesStack;
typedef std::stack<FieldData> fieldsDataStack;
typedef std::stack<std::string> stringStack;
typedef std::list<std::string> stringList;

class Table
{
private:
  Record* _records = nullptr;
  fieldsTypesMap *_fieldsTypification = nullptr;
  fieldsNamesMap *_fieldsTitling = nullptr;
  Record* create_record(const fieldsTypesStack &types,
                        const fieldsDataStack  &dataset);


public:  
  Table(const fieldsTypesStack &fieldsTypes,
        const stringStack &fieldsNames);


  Table* push_back(const Record &newRecord);
  Table* push_back(const fieldsDataStack &dataSet);

  static Field* create_field(const fieldType   &type = INTEGER,
                             const std::string &name = "untitled");

};

#endif // TABLE_H
