#pragma once
#include <SFML/Graphics.hpp>

//class Ball {
//private:
//	float x, y, w, h; // coordinates, width, height
//	float dx, dy, speed; // x and y axises acceleration, ball's speed
//	float dir;
//	Image image;
//	Texture texture;
//	Sprite sprite;
//public:
//	Ball(String F, int X, int Y, float W, float H) {
//		w = W, h = H;
//		x = X, y = Y;
//		image.loadFromFile("images//" + F);
//		texture.loadFromImage(image);
//		sprite.setTexture(texture);
//		sprite.setTextureRect(IntRect(w, h, w, h));
//	}
//
//};

namespace Ball {
	const float R = 10.f;
	const float D = 2*R;
	const float XSPEED = 1.f;
	const float YSPEED = 1.f;
}

