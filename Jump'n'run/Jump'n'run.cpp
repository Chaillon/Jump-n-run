// Jump'n'run.cpp : Defines the entry point for the console application.
//https://github.com/Chaillon/Jump-n-run

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;


class GameWindow : public Gosu::Window {
public:

	vector <Gosu::Image> Bewegung;
	Gosu::Image hintergrund;
	Gosu::Image hintergrund2;
	Gosu::Image MMSprung;
	Gosu::Image wall_160_59;
	Gosu::Image wall_60_128;
	int x = 1024;
	int xhintergrund1 = 1595;
	int xhintergrund2 = 0;
	int geschwindigkeit = 2;
	int cnt = 0;
	int hoehe = 500;
	int bild = 1;
	int i = 0;
	int zeit = 0;
	int time = 40;
	double sprung = 0;
	bool spacealt = false;
	bool richtung = false;
	int Figur = 0;




	GameWindow() :Window(1600, 552), 
		hintergrund("wolken.jpg"), hintergrund2("wolken.jpg"),
		wall_160_59("Wand_160_59.png"), wall_60_128("Wand_60_128.png"), MMSprung("4.png")

	{
		set_caption("Jump'n'Run-BITCHES");
		Gosu::Image eins("1.png");
		Gosu::Image zwei("3.png");
		Gosu::Image drei("2.png");
		Gosu::Image vier("3.png");
		Gosu::Image fuenf("4.png");
		Bewegung.push_back(eins);
		Bewegung.push_back(zwei);
		Bewegung.push_back(drei);
		Bewegung.push_back(vier);
		Bewegung.push_back(fuenf);
	}



	void update() override {
		
		if (xhintergrund1 >= -1595)
		{
			xhintergrund1 -= geschwindigkeit;
		}
		else
		{
			xhintergrund1 = 1595;
		}
		if (xhintergrund2 >= -1595)
		{
			xhintergrund2 -= geschwindigkeit;
		}
		else
		{
			xhintergrund2 = 1595;
		}

		x -= 2;
		if (x % 100 == 0) {
			cnt++;

		}

		

		if (sprung)
		{
			Figur = 4;
		}
		else if(!sprung)
		{
			zeit = (zeit + 1) % time;
			Figur = ((zeit * 4) / time);
		}

		if ((input().down(Gosu::KB_SPACE)) && spacealt == false)
		{
			spacealt = true;
			Figur = 4;
			sprung = 1;
		}

		else if (spacealt == true && i < 20 && !richtung)
		{
			hoehe -= 4;
			i++;
		}

		else if (spacealt == true && i < 40)
		{
			hoehe += 4;
			i++;
		}

		else if ((!input().down(Gosu::KB_SPACE)) && spacealt == true) {
			spacealt = false;
			i = 0;
			sprung = 0;
		}

	}



	void draw() override {

		hintergrund.draw_rot(
			xhintergrund1, 0.0, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		hintergrund2.draw_rot(
			xhintergrund2, 0.0, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_160_59.draw_rot(
			x, 500, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_60_128.draw_rot(
			x, 300, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_160_59.draw_rot(
			x, 50, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		Bewegung.at(Figur).draw_rot(
			5, hoehe, 0.0,
			0.0,	//Rotation in Grad
			0.0, 1.0
		);
		
	}
};


int main()
{

	GameWindow window;
	window.show();
	
}

