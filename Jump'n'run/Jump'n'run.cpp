// Jump'n'run.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window {
public:

	Gosu::Image hintergrund;
	Gosu::Image MMrechts;
	Gosu::Image MMlinks;
	Gosu::Image MMMitte;
	Gosu::Image MMSprung;
	Gosu::Image wall_517_190;

	GameWindow() :Window(1024, 531), hintergrund("hintergrund.jpg"), wall_517_190("Wand_160_59.png"), MMrechts("1.png"), MMlinks("2.png"), MMMitte("3.png"), MMSprung("4.png")
	{
		set_caption("Jump'n'Run-BITCHES");
	}

	double x = 1024;
	int hmm = 44;

	void update() override {
		if (x > 0) {
			x -= 1,5;
		}
		else {
			x = 1024;
		}
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
		MMrechts.draw_rot(
			10, (500 - hmm), 0.0, 
			0.0, //Rotation in Grad
			0.0, 0.0
		);
		MMlinks.draw_rot(
			60, (500 - hmm), 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);
		MMMitte.draw_rot(
			200, (500 - hmm), 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);
		MMSprung.draw_rot(
			300, (500 - hmm), 0.0,
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

