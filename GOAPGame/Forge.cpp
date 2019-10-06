#include "Forge.h"
#include "Actor.h"

Forge::Forge()
	: Action(20.0f)
{

}

bool Forge::CheckCondition(Actor* a, World& w)
{
	return true;
}


void Forge::SetEffect(Actor* a, World& w)
{
	w.weapon += 1;
	a->energy -= 2;
}

bool Forge::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Create new weapon  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Forge ..." << std::endl;

	return false;
}