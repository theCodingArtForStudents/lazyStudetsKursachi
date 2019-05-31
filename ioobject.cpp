#include "ioobject.h"

ioObject::ioObject()
{

}

std::istream &operator >>(std::istream &in, ioObject &obj)
{  
  return obj.show(in);
}

std::ostream &operator <<(std::ostream &out, ioObject &obj)
{
  return out << &obj.show(out);
}
