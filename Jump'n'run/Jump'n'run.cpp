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
int ii = 0;
int x = wide_bgnd;
int cnt_wallrechts = 0;

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
		v1.push_back(Wall(1600, y_val_ran, wide, height, wall_160_59));
		ii++;
		cnt_wallrechts = 0;
	}
	else
	{
		wide = 60;
		height = 128;
		int y_val_ran = Gosu::random(height+100, height_bgnd - height);
		v1.push_back(Wall(1600, y_val_ran, wide, height, wall_60_128));
		ii++;
		cnt_wallrechts = 0;
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
	Gosu::Image wall_long;
	Gosu::Image gameover;
	vector<Wall> wallvec;
	vector<Wall>::iterator wall_it = wallvec.begin();
	vector<Wall>::iterator wall_it_aus = wallvec.begin();
	vector<Wall>::iterator wall_del = wallvec.begin();
	vector<Wall>::iterator wall_bevor = wallvec.end();
	

	
	int x2 = x - 200;
	int xhintergrund1 = 1595;
	int xhintergrund2 = 0;
	int geschwindigkeit = 2;
	int cnt = 0;
	int hoehe = 0;
	int bild = 1;
	int i = 0;
	int zeit = 0;
	int time = 40;
	bool sprung = false;
	bool spacealt = false;
	bool richtung = false;
	int Figur = 0;
	int cnt_v = 100;
	int cnt_g = 0;
	int j_h;
	int fx_val = 200;
	int new_floor;
	int t = 0;
	int cnt_beg = 675;
	bool new_floor_exist = false;
	bool gameover_b = false;


	GameWindow() :Window(wide_bgnd, height_bgnd),
		hintergrund("wolken.jpg"), hintergrund2("wolken.jpg"),
		wall_160_59("Wand_160_59.png"), wall_60_128("Wand_60_128.png"), MMSprung("4.png"), wall_long("Wall_long.png"), gameover("gameover.png")

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
		
		Wall wall2(wide_bgnd, 300, 160, 60, wall_160_59);
		Wall wall3(wide_bgnd, 400, 160, 60, wall_160_59);
		wallvec.push_back(wall3);
		wallvec.push_back(wall2);
		

	}

	void update() override {
	if(!gameover_b)
	{
		if (cnt_v == 100)
		{
			wallvec = create_wall(wallvec);
			wallvec = create_wall(wallvec);
			cnt_v = 0;
		}

		if (wallvec.size() < 20)
		{
			wallvec = create_wall(wallvec);
			cnt_v = 0;
		}

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
		x -= geschwindigkeit;
		cnt_beg--;
		if (cnt_beg > 0)
		{
			new_floor = 200;
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
		vector<Wall> wallvechelp;
		Wall wall1(0, height_bgnd, 160, 59, wall_160_59);
		wallvechelp.push_back(wall1);
		wall_it = wallvec.begin();
		//(*wall_it_aus).y_val = 0;
		wall_it_aus = wallvechelp.begin();
		new_floor_exist = false;
		if (cnt_beg <= 0)
		{
			while (!(wall_it == wallvec.end()))
			{
				if (((((*wall_it).x_val + (*wall_it).wide)) > fx_val) && ((*wall_it).x_val < (fx_val + 36)))
				{
					wall_it_aus = wall_it;
					new_floor_exist = true;

					
					if (((hoehe - 7) > (*wall_it_aus).y_val) && ((hoehe - 7) < ((*wall_it_aus).y_val + (*wall_it_aus).height)))
					{
						gameover_b = true;
					}
					break;
				}
				else
				{
					new_floor_exist = false;
				}
				wall_it++;
			}
			if (new_floor_exist)
			{
				if ((((*wall_it_aus).y_val > (hoehe - 7))))
				{
					new_floor = (*wall_it_aus).y_val;
				}
				else
				{
					new_floor = height_bgnd;
				}
				//new_floor_exist = false;
			}
			else
			{
				new_floor = height_bgnd;
			}

		}

		int v0 = 40;
		if ((input().down(Gosu::KB_SPACE)) && spacealt == false)
		{
			Figur = 4;
			spacealt = true;
			sprung = true;
			/*if (spacealt == true && i < 40 && !richtung)
			{
				hoehe -= 6;
				i++;
			}*/

		}
	

		else if (spacealt == true && i < 40)
		{
			hoehe -= 6;
			i++;
		}

		else if (/*spacealt == true &&*/ hoehe < new_floor)
		{
			hoehe += 6;
			i++;
		}

		else if ((!input().down(Gosu::KB_SPACE)) && spacealt == true && i >= 40) {
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

		// cnt_v++;
		int j = j_h;

		wall_it = wallvec.begin();
		while (!(wall_it == wallvec.end()))
		{

			(*wall_it).x_val = x + j * 180;
			j++;
			wall_it++;

		}

		wall_del = wallvec.begin();

		if ((*wall_del).x_val == (-300))
		{
			ii--;
			wallvec.erase(wall_del);
			j_h++;

		}



		//cout << wallvec.size() << endl;
		//cout << new_floor << endl;



	}
	else if (input().down(Gosu::KB_SPACE))
	{
		x = wide_bgnd-100;
		cnt_beg = 625;
		gameover_b = false;
		hoehe = 200;
	}
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

		wall_it = wallvec.begin();
		while (!(wall_it == wallvec.end()))
		{
			(*wall_it).wall.draw_rot(
				(*wall_it).x_val, (*wall_it).y_val, 0.0,
				0.0, 0.0,
				0.0
			);
			wall_it++;
		}

		wall_long.draw_rot(
			x - 1550, 200, 0.0,
			0.0, //Rotation in Grad
			0.0, 0.0
		);

		Bewegung.at(Figur).draw_rot(
			fx_val, hoehe, 0.0,
			0.0,	//Rotation in Grad
			0.0, 1.0
		);
		if (((hoehe) > (height_bgnd-44) )| gameover_b == true)
		{
			gameover.draw_rot(
				0, 0, 0.0,
				0.0,	//Rotation in Grad
				0.0, 0.0, 1.0
			);
			gameover_b = true;
			

		}
		
	}
};


int main()
{

	GameWindow window;
	window.show();
	
}

