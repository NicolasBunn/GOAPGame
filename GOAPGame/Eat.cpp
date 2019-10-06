#include "Eat.h"
#include "Actor.h"

Eat::Eat()
	: Action(10.0f)
{

}

bool Eat::CheckCondition(Actor* a, World& w)
{
	if (a->energy < 3)
	{
		return true;
	}

	return false;
}

void Eat::SetEffect(Actor* a, World& w)
{
	
}

bool Eat::ExecuteAction(float timer)
{
	return false;
}