// Jump'n'run.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window {
public:

	Gosu::Image hintergrund;
	Gosu::Image wall_517_190;

	GameWindow() :Window(1024, 531), hintergrund("hintergrund.jpg"), wall_517_190("Wand_160_59.png")
	{
		set_caption("Jump'n'Run-BITCHES");
	}
	int x = 0;

	void update() override {
		x = (x + 1) % 1024;
	}

	void draw() override {
		hintergrund.draw_rot(
			0.0, 0.0, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_517_190.draw_rot(
			x, 500, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);
	}
};


int main()
{
	GameWindow window;
	window.show();
}

