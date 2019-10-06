#include "Hunt.h"
#include "Actor.h"

Hunt::Hunt()
	: Action(20.0f)
{

}

bool Hunt::CheckCondition(Actor* a, World& w)
{
	if (w.weapon > 0)
	{
		return true;
	}

	return false;
}


void Hunt::SetEffect(Actor* a, World& w)
{
	w.meat += 10;
	w.weapon -= 1;
	a->energy -= 5;
}

bool Hunt::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Hunter is done !  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Hunting ..." << std::endl;

	return false;
}