#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "ioobject.h"

#include <iostream>

class lineedit : public ioObject
{
private:
    std::string _title;
    std::string _value;
public:
  lineedit();
  std::istream &show(std::istream &in)  override;
  std::ostream &show(std::ostream &out) override;
};

#endif // LINEEDIT_H
