// Jump'n'run.cpp : Defines the entry point for the console application.
//https://github.com/Chaillon/Jump-n-run

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

int wide_bgnd = 1600;
int height_bgnd = 552;

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
int ii = 1;
vector<Wall> create_wall(vector<Wall> v)
{
	vector<Wall> v1 = v;
	double geom = Gosu::random(0,100);
	int wide;
	int height;
	Gosu::Image wall_160_59("Wand_160_59.png");
	Gosu::Image wall_60_128("Wand_60_128.png");
	
	if (geom >= 50)					//dann across
	{
		wide = 160;
		height = 59;
		int y_val_ran = Gosu::random(height+100, height_bgnd - height); // beliebigen Y-Wert generieren
		v1.push_back(Wall((v1.at(ii-1).x_val + 300), y_val_ran, wide, height, wall_160_59));
		ii++;
	
	}
	else
	{
		wide = 60;
		height = 128;
		int y_val_ran = Gosu::random(height+100, height_bgnd - height);
		v1.push_back(Wall((v1.at(ii - 1).x_val + 300), y_val_ran, wide, height, wall_60_128));
		ii++;
	}
	//vector<Wall> v_pnt = v1;
	return v1;
}

class GameWindow : public Gosu::Window {
public:

	vector <Gosu::Image> Bewegung;
	Gosu::Image hintergrund;
	Gosu::Image hintergrund2;
	Gosu::Image MMSprung;
	Gosu::Image wall_160_59;
	Gosu::Image wall_60_128;
	vector<Wall> wallvec;
	vector<Wall>::iterator wall_it = wallvec.begin();
	vector<Wall>::iterator wall_del = wallvec.begin();

	int x = wide_bgnd;
	int xhintergrund1 = 1595;
	int xhintergrund2 = 0;
	int geschwindigkeit = 2;
	int cnt = 0;
	int hoehe = height_bgnd;
	int bild = 1;
	int i = 0;
	int zeit = 0;
	int time = 40;
	bool sprung = false;
	bool spacealt = false;
	bool richtung = false;
	int Figur = 0;
	int cnt_v = 0;
	int cnt_g = 1;



	GameWindow() :Window(wide_bgnd, height_bgnd),
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
Wall wall2(wide_bgnd, 500, 60, 128, wall_60_128);
wallvec.push_back(wall2);
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

		/*if (x > 0)
		{
			x -= geschwindigkeit;
		}
		/*else
		{
			x = wide_bgnd;
		}*/
		x -= geschwindigkeit;
		wallvec.at(1).x_val = x;



		if (sprung)
		{
			Figur = 4;
		}
		else if (!sprung)
		{
			zeit = (zeit + 1) % time;
			Figur = ((zeit * 4) / time);
		}

		int v0 = 40;
		if ((input().down(Gosu::KB_SPACE)) && spacealt == false)
		{
			Figur = 4;
			spacealt = true;
			sprung = true;
		}

		else if (spacealt == true && i < 30 && !richtung)
		{
			hoehe -= 4;
			i++;

		}

		else if (spacealt == true && i < 60)
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

		cnt_v++;
		int j = 2;

		wall_it = wallvec.begin();
		while (!(wall_it == wallvec.end()))
		{
			(*wall_it).x_val = x + j * 250;
			j++;
			wall_it++;
		}
		/*if (wallvec.size() >= 20)
		{
			wall_del = wallvec.begin();
			wallvec.erase(wall_del);
			j--;
		}*/
		if (cnt_v == 50)
		{
			wallvec = create_wall(wallvec);
			cnt_v = 0;
		}

		cout << cnt_v << endl;
		

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

		/*wallvec.at(1).wall.draw_rot(
			x , 100, 0.0,
			0.0,0.0,
			0.0
		);*/

		wall_it = wallvec.begin();
		while(!(wall_it == wallvec.end()))
		{
			(*wall_it).wall.draw_rot(
				(*wall_it).x_val, (*wall_it).y_val, 0.0,
				0.0, 0.0,
				0.0
			);
			wall_it++;
		}
		

		/*wallvec.at(ii).wall.draw_rot(
			wallvec.at(ii).x_val, wallvec.at(ii).y_val, 0.0,
			0.0, 0.0,
			0.0
		);*/
		cout << ii << endl;

		wall_160_59.draw_rot(
			x-1000, 500, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_60_128.draw_rot(
			x-600, 300, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_160_59.draw_rot(
			x-400, 400, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		wall_160_59.draw_rot(
			x - 200, 400, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		Bewegung.at(Figur).draw_rot(
			200, hoehe, 0.0,
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

