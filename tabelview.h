#ifndef TABELVIEW_H
#define TABELVIEW_H

#include <iostream>

#include "tabel.h"
#include "ioobject.h"

class tabelView : public ioObject
{
  Tabel _anyTabel;

  std::string& buildTable();
public:
  tabelView();

  std::ostream &show(std::ostream &out) override;
};

#endif // TABELVIEW_H
