// Jump'n'run.cpp : Defines the entry point for the console application.
//https://github.com/Chaillon/Jump-n-run

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
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


class GameWindow : public Gosu::Window{
public:

	Gosu::Image hintergrund;
	Gosu::Image MMrechts;
	Gosu::Image MMlinks;
	Gosu::Image MMMitte;
	Gosu::Image MMSprung;
	Gosu::Image wall_160_59;
	Gosu::Image wall_60_128;
	vector<Wall> wallvec;

	GameWindow() :Window(1024, 531), 
		hintergrund("hintergrund.jpg"), 
		wall_160_59("Wand_160_59.png"), wall_60_128("Wand_60_128.png"),
		MMrechts("1.png"), MMlinks("2.png"), MMMitte("3.png"), MMSprung("4.png")

	{
		set_caption("Jump'n'Run-BITCHES");
		Wall wall(10, 10, 10, 10, wall_160_59);
		wallvec.push_back(wall);

	}

	int x = 1024;
	int cnt = 0;
	double x_200 = x + 200;
	double x_400 = x + 400;
	double x_600 = x + 600;
	int hoehe = 500;
	int bild = 1;
	int i = 0;
	double zeit = 0;
	double time = 40;
	double sprung = 0;
	bool space = false;
	bool richtung = false;

	//vector<Wall_Across> wall_list;
	//	//wall_list.at(0) = wall;

	
	void update() override {

		x -= 2;
		if (x % 100 == 0) {
			cnt++;

		}

		if (sprung)
		{
			bild = 4;
		}

		if (x > -0) {
			x -= 1.5;
		}
		else 
		{
			x = 1024;

		}

		if (zeit < time)
		{
			zeit = (zeit + 1);
		}
		else if (zeit == time)
		{
			zeit = 0;
		}

		if (zeit < (time / 4) && !sprung)
		{
			bild = 1;
		}
		else if (zeit >(time / 4) && time < (time / 2) && !sprung)
		{
			bild = 2;
		}
		else if ((zeit >= (time / 2) && zeit < (0.75*time)) && !sprung)
		{
			bild = 3;
		}
		else if(!sprung)
		{
			bild = 2;
		}


		if ((input().down(Gosu::KB_SPACE)) && space == false) 
		{
			space = true;
			bild = 4;
			sprung = 1;
		}

		else if (space == true && i < 20 && !richtung)
		{
			hoehe -= 4;
			i++;
		}

		else if (space == true && i < 40)
		{
			hoehe += 4;
			i++;
		}

		else if ((!input().down(Gosu::KB_SPACE)) && space == true) {
			space = false;
			i = 0;
			sprung = 0;
		}
		
		

		Wall wall1()
		/*int i = 0;
		int random = Gosu::random(1, 2);
		if (random == 1)
		{
			Wall wall(wall_list.at(i - 1), random
				wall_list.push_back
				i++;
		}*/
		



		
	}

	void draw() override {

		

		hintergrund.draw_rot(
			0.0, 0.0, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wallvec.at(0).wall.draw_rot(
			wallvec.at(0).x_val,wallvec.at(0).y_val, 0.0,
			0.0,0.0,
			0.0
		);

			wall_160_59.draw_rot(
			x, 500, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_60_128.draw_rot(
			x_400, 300, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_160_59.draw_rot(
			x, 50, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		if (bild == 1)
		{
			MMrechts.draw_rot(
				10, 500, 0.0,
				0.0, //Rotation in Grad
				0.0, 1.0
			);
		}

		else if (bild == 2)
		{
			MMMitte.draw_rot(
				10, 500, 0.0,
				0.0, //Rotation in Grad
				0.0, 1.0
			);
		}

		else if (bild == 3)
		{
			MMlinks.draw_rot(
				10, 500, 0.0,
				0.0, //Rotation in Grad
				0.0, 1.0
			);
		}
		else if (bild == 4)
		{
			MMSprung.draw_rot(
				10, hoehe, 0.0,
				0.0, //Rotation in Grad
				0.0, 1.0
			);
		}
		
	}
};


int main()
{
	GameWindow window;
	window.show();
	
}

