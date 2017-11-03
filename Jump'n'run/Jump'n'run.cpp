// Jump'n'run.cpp : Defines the entry point for the console application.
//https://github.com/Chaillon/Jump-n-run

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;


class Wall{
public:
	int x_val, y_val, wide, height;
	Gosu::Image wall;
	Wall(int32_t x_val, int32_t y_val, int32_t wide, int32_t height, Gosu::Image wall_60_128) : x_val(x_val), y_val(y_val), wide(wide), height(height), wall("Wand_60_128.png") 
	{
		this->x_val = x_val;
		this->y_val = y_val;
		this->wide = wide;
		this->height = height;
		this->wall = wall_60_128;
	};

};


class GameWindow : public Gosu::Window {
public:

	vector <Gosu::Image> Bewegung;
	Gosu::Image hintergrund;
	Gosu::Image hintergrund2;
	Gosu::Image MMSprung;
	Gosu::Image wall_160_59;
	Gosu::Image wall_60_128;
	vector<Wall> wallvec;

	int xhintergrund1 = 1595;
	int xhintergrund2 = 0;
	int geschwindigkeit = 2;
	int hoehe = 500;
	int bild = 1;
	int i = 0;
	int zeit = 0;
	int time = 40;
	bool sprung = false;
	bool spacealt = false;
	bool richtung = false;
	int Figur = 0;





	GameWindow() :Window(1600, 552), 
		hintergrund("wolken.jpg"), hintergrund2("wolken.jpg"),
		wall_160_59("Wand_160_59.png"), wall_60_128("Wand_60_128.png"), MMSprung("4.png")

	{
		set_caption("Jump'n'Run");
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
		Wall wall1(0, 0, 160, 59, wall_160_59);
		Wall wall2(0, 300, 60, 129, wall_60_128);
		wallvec.push_back(wall1);
		wallvec.push_back(wall2);
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
		
		if (sprung)
		{
			Figur = 4;
		}
		else if (!sprung)
		{
			zeit = (zeit + 1) % time;
			Figur = ((zeit * 4) / time);
		}


		if ((input().down(Gosu::KB_SPACE)) && spacealt == false)
		{
			Figur = 4;
			spacealt = true;
			sprung = true;
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
			sprung = false;
			spacealt = false;
			richtung = false;
			i = 0;
		}

		else if (input().down(Gosu::KB_SPACE) && spacealt == true)
		{
			zeit = (zeit + 1) % time;
			Figur = ((zeit * 4) / time);
		};
	};

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

		wallvec.at(0).wall.draw_rot(
			wallvec.at(0).x_val,wallvec.at(0).y_val, 0.0,
			0.0,0.0,
			0.0
		);

		wallvec.at(1).wall.draw_rot(
			wallvec.at(1).x_val, wallvec.at(1).y_val, 0.0,
			0.0, 0.0,
			0.0
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

