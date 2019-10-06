#include "GetWeapon.h"
#include "Actor.h"

GetWeapon::GetWeapon()
	: Action(10.0f)
{

}

bool GetWeapon::CheckCondition(Actor* a, World& w)
{
	return true;
}


void GetWeapon::SetEffect(Actor* a, World& w)
{
	w.weapon -= 1;
	a->energy -= 1;
}

bool GetWeapon::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "GetWeapon is done !  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "GetWeapon ..." << std::endl;

	return false;
}