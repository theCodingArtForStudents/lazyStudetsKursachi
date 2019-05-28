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
typedef std::map<std::string, FieldData> Raw;

//template  <typename T> typedef std::map<std::string, T> mypair;

 //mypair PaitType;

typedef std::vector<Raw *> Record;

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
  bool _isEmpty = true;

  Record* create_record(const fieldsTypesStack &types,
                        const fieldsDataStack  &dataset);

//  mypair _pair;

public:  
  Table(){}
  Table(fieldsTypesStack &fieldsTypes,
        stringStack &fieldsNames);
  Table(Table* newTable);
  ~Table();

  Table* push_back(const Record &newRecord);
  Table* push_back(fieldsDataStack &dataSet);
  Table* pop();
  Table* erase();
  Table* clear();




  static Raw* create_field(const fieldType   &type = INTEGER,
                           const std::string &name = "untitled");

  Raw* operator [](const size_t &index);
//  Table* operator =(Table* )

  fieldsTypesMap *fieldsTypification() const;
  fieldsNamesMap *fieldsTitling() const;
  bool isEmpty();
};

#endif // TABLE_H
