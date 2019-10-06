#include "EatMeat.h"
#include "Actor.h"

EatMeat::EatMeat()
	: Action(10.0f)
{

}

bool EatMeat::CheckCondition(Actor* a, World& w)
{
	if (w.meatReady > 0)
	{
		return true;
	}
	return false;
}

void EatMeat::SetEffect(Actor* a, World& w)
{
	a->energy += 3;
	w.meatReady--;
}

bool EatMeat::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Finish eating meat " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Eating meat..." << std::endl;

	return false;
}