#ifndef ACTIONTYPE_H
#define ACTIONTYPE_H


class ActionType
{
public:
  ActionType(){}
  virtual ~ActionType();

  virtual void native_action();
};

#endif // ACTIONTYPE_H
