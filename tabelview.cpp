#include "tabelview.h"




std::ostream &tabelView::show(std::ostream &out)
{
  return out << buildTable();
}

std::string &tabelView::buildTable()
{
  std::string *result = new std::string("");
  auto recs = _anyTabel.records();
  for(size_t i = 0; i < recs.size(); i ++)
    {
      for(auto&& [key, val] : *(recs)[i])
        {
          if( i == 0)
            {
              result->append(key);
            }
          else
            {
              switch (int(val.type())) {
                  case STRING:
                      result->append(*val.data()->_cData);
                      break;
                  }
            }
          result->append(" |");
        }
      result->append("\n");
    }
  return *result;
}
