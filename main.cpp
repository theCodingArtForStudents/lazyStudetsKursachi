
#include "tabel.h"
//#include "actionmanager.h"
#include <iostream>

void o(std::string*)
{
  std::cout << "took the -o param" << std::endl;
}

int main(int argc, char* argv[])
{

  fieldsTypesStack typeStack;

  typeStack.push(STRING);
  typeStack.push(INTEGER);

  stringStack nameStack;

  nameStack.push("Initial");
  nameStack.push("weight");

  Tabel *t = new Tabel( typeStack, nameStack);

  stringStack fNMtmp;
//      fNMtmp = t->fieldsTitling();
  for(auto&& [key, val] : t->fieldsTitling())
    {
      fNMtmp.push(val);
    }

  fieldsDataStack fDStmp;

//  FieldType<std::string> *str = new FieldType("Carl J");
//  FieldType<int> *i = new  FieldType<int>(90);

  FieldType str1 = std::string("Carl J");
  FieldType i1 = 90;


  fDStmp.push(str1);
  fDStmp.push(i1);
  fDStmp.push(std::string("Frank T"));
  fDStmp.push(double(10.9));
  fDStmp.push(std::string("Sean J"));
  fDStmp.push(8.5);


  t->push_back(fNMtmp, fDStmp);

//  for( auto [type, name] : *fNMtmp)
//    std::cout << "type: " << int(type) << " name: " << name << std::endl;




  return 0;
}
