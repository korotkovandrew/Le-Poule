#pragma once
#include <SFML/Graphics.hpp>

class ball : sf::Sprite
{
	float x, y;
	
	ball(int _x = 0, int _y = 0) : x(_x), y(_y) {
		
	};
};

