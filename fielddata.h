#ifndef FIELDDATA_H
#define FIELDDATA_H


class FieldData
{
public:
  FieldData();
  virtual ~FieldData();
  virtual FieldData* operator =(void*);
};

#endif // FIELDDATA_H
