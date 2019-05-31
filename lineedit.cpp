#include "lineedit.h"

lineedit::lineedit()
{

}

std::istream &lineedit::show(std::istream &in)
{
  char tmp[255];
  in.getline(tmp, in.gcount());
  std::string s = tmp;
  this->_value = s;
  return in;
}

std::ostream &lineedit::show(std::ostream &out)
{
  return out << _title;
}
