// Jump'n'run.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window {
public:

	Gosu::Image hintergrund;

	GameWindow() :Window(1024, 531), hintergrund("hintergrund.jpg")
	{
		set_caption("Jump'n'Run-BITCHES");
	}

	void update() override {

	}

	void draw() override {
		hintergrund.draw_rot(
			0.0, 0.0, 0.0,
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

