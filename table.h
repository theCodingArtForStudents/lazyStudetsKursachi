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
typedef std::map<std::string, FieldData> Field;

typedef std::vector<Field *> Record;

typedef std::stack<fieldType> fieldsTypesStack;
typedef std::stack<FieldData> fieldsDataStack;
typedef std::stack<std::string> stringStack;
typedef std::list<std::string> stringList;

class Table
{
private:
  Record* _fields = nullptr;

  Record* create_record(const fieldsTypesStack &types,
                        const fieldsDataStack  &dataset);

  Field* create_field(const fieldType   &tipe = INTEGER,
                      const std::string &name = "untitled");

public:  
  Table(const fieldsTypesStack &fieldsTypes,
        const stringStack      &fieldsNames);

  Table* push_back(const fieldsDataStack &dataSet);
};

#endif // TABLE_H
