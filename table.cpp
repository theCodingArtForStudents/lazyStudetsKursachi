#include "table.h"



Field *Table::create_field(const fieldType &tipe, const std::string &name)
{
  _fields = new Record();
  _fields[0] = new Field();
}

Table::Table(const fieldsTypesStack &fieldsTypes, const stringStack &fieldsNames)
{

}
