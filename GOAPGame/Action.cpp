#include "Action.h"
#include "Actor.h"


Action::Action(float c)
	: costAction(c)
{

}

Action::Action(const Action& a)
	: costAction(a.costAction)
{

}

