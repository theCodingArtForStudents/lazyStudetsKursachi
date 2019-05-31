#ifndef TABLE_H
#define TABLE_H

#include <variant>
#include <map>
#include <stack>
#include <list>

#include <vector>
#include <bits/stl_iterator_base_types.h>
#include <iterator>

#include "field.h"



typedef std::map<std::string, FieldType> Raw;

typedef std::vector<Raw *> Record;

typedef std::map<std::string, FieldType>  fieldsTypesMap;
typedef std::map<FieldType, std::string>  fieldsNamesMap;
typedef std::stack<FieldType> fieldsTypesStack;
typedef std::stack<FieldType> fieldsDataStack;
typedef std::stack<std::string> stringStack;
typedef std::list<std::string> stringList;

class Tabel
{
private:
  Record _records;
  fieldsTypesMap *_fieldsTypification = nullptr;
  fieldsNamesMap *_fieldsTitling = nullptr;
  bool _isEmpty = true;

  Record* create_record(const fieldsTypesStack &types,
                        const fieldsDataStack  &dataset);

//  mypair _pair;

public:  
  Tabel(){}
  Tabel(fieldsTypesStack &fieldsTypes,
        stringStack &fieldsNames);
  Tabel(Tabel* newTable);
  ~Tabel();

  Tabel& create_fields(fieldsTypesStack &fieldsTypes,
                stringStack &fieldsNames);

  Tabel& push_back(stringStack &fieldsNames, fieldsDataStack &dataSet);
  Tabel& pop();
  Tabel& erase();
  Tabel& clear();

  auto begin();
  auto end();

  size_t count();
  bool configered();


  Raw& create_field(const fieldType   &type = INTEGER,
                    const std::string &name = "untitled");

  Raw &operator [](const size_t &index);
//  Table* operator =(Table* )

  fieldsTypesMap &fieldsTypification() const;
  fieldsNamesMap &fieldsTitling();
  bool isEmpty();
  Record records() const;
};

#endif // TABLE_H
