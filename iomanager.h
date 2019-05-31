#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <iostream>
#include <fstream>

#include <vector>
#include <map>


class iomanager
{
public:
  iomanager();

  std::ostream& show();
  std::istream& take();
};

#endif // IOMANAGER_H
