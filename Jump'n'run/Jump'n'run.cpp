// Jump'n'run.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window {
public:
	GameWindow() :Window(1000, 500)
	{
		set_caption("Jump'n'Run-BITCHES");
	}

	void update() override {

	}

	void draw() override {

	}
};


int main()
{
	GameWindow window;
	window.show();
}

