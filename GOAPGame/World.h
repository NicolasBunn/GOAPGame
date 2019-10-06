#pragma once

class World
{
	public:

		World(int w = 0, int m = 0, int f = 0);

		int weapon;
		int meat;
		int fruit;

		int fruitReady;
		int meatReady; 
};