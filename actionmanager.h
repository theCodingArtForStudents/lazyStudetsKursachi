#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <vector>
#include <map>
#include <stack>

#include "actiontype.h"

typedef std::map<std::string, ActionType*> actionsMap;
typedef std::vector<ActionType*> actionsVector;
typedef std::stack<ActionType*> actionStack;

const std::string std_actionName = "untitled_action";

class ActionManager
{
private:
  actionsVector _actions;
  actionsMap _actionsMap;
public:
  ActionManager();
  ~ActionManager();
  ActionManager(actionStack &newFunctional);

  ActionManager& push_back(ActionType &function,
                          const std::string &actionName = std_actionName);

  ActionManager& pop();
  ActionManager& extrac(const std::string &actionName = std_actionName);
  ActionManager& clear();
  bool isEmpty();
};

#endif // INPUTMANAGER_H
