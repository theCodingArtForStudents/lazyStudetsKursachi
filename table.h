#ifndef TABLE_H
#define TABLE_H

#include <variant>
#include <map>

enum fieldType
{
  INTEGER,
  STRING,
  COUNTER,
  DOUBLE
};

typedef  std::variant<int, std::string, size_t, double> FieldType;

typedef std::map<std::string, FieldType> Field;

class Table
{
  Field* fields = nullptr;
public:
  Table();
};

#endif // TABLE_H
