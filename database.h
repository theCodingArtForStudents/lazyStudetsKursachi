#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <stack>

#include "tabel.h"

typedef std::map<std::string, Tabel*> Tabels;

typedef std::map<std::string, fieldsTypesStack> Maped_fieldsTypesStack;
typedef std::map<std::string, fieldsDataStack> Maped_fieldsDataStack;
typedef std::map<std::string, stringStack> Maped_fieldsNamesStack;


class DataBase{

private:
  Tabels _tables;
  bool _isEmpty = true;

public:
  DataBase();
  DataBase(stringStack &tabelsNames,
           Maped_fieldsTypesStack &tabels_fieldsTypes,
           Maped_fieldsNamesStack &tabels_fieldsNames);
  ~DataBase();

  bool insert(const std::string &tabelName,
              stringStack &fieldsNames,
              fieldsDataStack &fieldsData);
  bool update(const std::string &tabelName,
              stringStack &fieldsNames,
              fieldsDataStack &oldData, fieldsDataStack &newData);
  Maped_fieldsDataStack &select(const std::string &tabelName,
                                stringStack &fieldsNames);
  Maped_fieldsDataStack &select(const std::string &tabelName,
                                const std::string &fieldsName = "*");
  bool isEmpty();

  bool clear();
};

#endif
