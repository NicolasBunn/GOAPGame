#include "PickFruit.h"
#include "Actor.h"

PickFruit::PickFruit()
	: Action(30.0f)
{

}

bool PickFruit::CheckCondition(Actor* a, World& w)
{
	return true;
}


void PickFruit::SetEffect(Actor* a, World& w)
{
	w.fruit += 10;
	a->energy -= 10;
}

bool PickFruit::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "PickFruit is done !  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Picking ..." << std::endl;

	return false;
}