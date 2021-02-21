#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"

const unsigned int SC_W = 720;
const unsigned int SC_H = 360;




using namespace sf;
int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(SC_W, SC_H), "SFML Works!", Style::Default, settings);

	Clock clock;

	bool bounce = false;
	int dx = 1, dy = 1;
	float x, y;
	float a = 0;

	CircleShape ball(Ball::R);
	ball.setFillColor(Color::Cyan);
	ball.setPosition(SC_W / 2 - Ball::R, SC_H / 2 - Ball::R);

	////---- Main Loop ----////
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 2000;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// определение координат шара
		x = ball.getPosition().x, y = ball.getPosition().y;

		// передвижение
		if (!bounce)
		{
			if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
				ball.move(0, -1 * time * Ball::YSPEED);
			if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
				ball.move(0, 1 * time * Ball::YSPEED);
			if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
				ball.move(-1 * time * Ball::XSPEED, 0);
			if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
				ball.move(1 * time * Ball::XSPEED, 0);

			// checking OoB
			if (x < 0 || x + Ball::D > SC_W || y < 0 || y + Ball::D > SC_H) { bounce = true; a = 4; };
		}
		else
		{
			a -= 0.001;
			if (a < 0 || Mouse::isButtonPressed(Mouse::Right)) { bounce = false; a = 0; }

			if (y < 0) dy = -dy;
			else if (x < 0) dx = -dx;
			else if (y + Ball::D > SC_H) dy = -dy;
			else if (x + Ball::D > SC_W) dx = -dx;

			ball.move(dx * time * a * Ball::XSPEED, dy * time * a * Ball::YSPEED);
		}


		ball.setFillColor(bounce ? Color::Green : Color::Red);
		window.clear(Color::White);
		window.draw(ball);
		window.display();
	}
	return 0;
}