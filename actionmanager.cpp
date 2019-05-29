#include "actionmanager.h"

ActionManager::ActionManager()
{

}

ActionManager::ActionManager(actionStack &newFunctional)
{
  while ( ! newFunctional.empty() )
    {
      _actions.push_back( newFunctional.top() );
      newFunctional.pop();
    }
}

ActionManager &ActionManager::push_back(ActionType &function,
                                      const std::string &actionName)
{
  if( actionName != std_actionName )
    _actionsMap[actionName] = &function;

  _actions.push_back(&function);

  return *this;
}

ActionManager &ActionManager::pop()
{
  _actions.pop_back();
  _actionsMap.erase(_actionsMap.end());
  return *this;
}

ActionManager &ActionManager::extrac(const std::string &actionName)
{
  _actionsMap.erase(_actionsMap.find(actionName));
  return *this;
}

ActionManager &ActionManager::clear()
{
  _actionsMap.clear();
  _actions.clear();

  return *this;
}

bool ActionManager::isEmpty()
{
  return _actions.empty() && _actionsMap.empty();
}

