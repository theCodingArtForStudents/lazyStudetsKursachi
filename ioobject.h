#ifndef IOOBJECT_H
#define IOOBJECT_H

#include <iostream>
#include <utility>

typedef std::pair<std::ostream&, std::istream&> uistream;

class ioObject
{
public:
  ioObject();
  virtual ~ioObject(){};

  virtual std::istream &show(std::istream &in) = 0;
  virtual std::ostream &show(std::ostream &out) = 0;

  friend std::ostream& operator <<(std::ostream& out, ioObject &obj);
  friend std::istream& operator >>(std::istream& in , ioObject &obj);
};

#endif // IOOBJECT_H
