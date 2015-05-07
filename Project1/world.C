#include "world.h"
#include "sprite.h"
#include "Tank.h"
#include "hellfire.h"
#include "birds.h"
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
namespace pilchiller
{
	world::world(ALLEGRO_DISPLAY *display, std::size_t window_width, std::size_t window_height)
	{
		p1vel=10;
		p2vel=10;
		font_20=al_load_ttf_font("Iron.ttf",20,0);
		font_70=al_load_ttf_font("Iron.ttf",70,0);
		shellfired=false;
		explosion_on=false;
		gameover=false;
		turn=0;
		width=window_width;
		height=window_height;
		angle1=-.5;
		angle2=-.5;
		tank1_x=50;
		tank2_x=1200;
		tank_y=650;
		ALLEGRO_BITMAP* sprite1=al_load_bitmap("Swag_tank.png");
		ALLEGRO_BITMAP* sprite2=al_load_bitmap("Swag_Barrel.png");
		background=al_load_bitmap("Swag_desert.png");
		tanks.push_back(new Tank(sprite1,sprite2,angle1,window_width,window_height,tank1_x,tank_y));
		tanks.push_back(new Tank(sprite1,sprite2,angle2,window_width,window_height,tank2_x,tank_y));
		if(background==NULL || sprite1==NULL || sprite2==NULL)
			assert(false);
	}

	world::~world()
	{

	}

    world::world(const world& other)
	{
    	assert(false);
    }

    world& world::operator =(const world& other)
	{
   		assert(false);
    }

    void world::handle_event(ALLEGRO_EVENT ev)
	{
		if(ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			bird.push_back(new birds(al_load_bitmap("sprite.png"),1280,720,ev.mouse.x,ev.mouse.y,rand()%20+10,rand()%5+3));
		if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
		{
			if(ev.keyboard.keycode==ALLEGRO_KEY_RIGHT)
			{
				if(turn==0)
					p1vel+=1;
				else
					p2vel+=1;
			}
			if(ev.keyboard.keycode==ALLEGRO_KEY_LEFT)
			{
				if(turn==0)
					p1vel-=1;
				else
					p2vel-=1;
			}
			if(ev.keyboard.keycode==ALLEGRO_KEY_UP)
			{
				tanks[turn]->rotate_turret_up();
				if(turn==0)
					angle1=angle1-.1;
				else
					angle2=angle2-.1;
			}
			if(ev.keyboard.keycode==ALLEGRO_KEY_DOWN)
			{
				tanks[turn]->rotate_turret_down();
				if(turn==0)
					angle1=angle1+.1;
				else
					angle2=angle2+.1;
			}
			if(ev.keyboard.keycode==ALLEGRO_KEY_SPACE)
			{
				if(shellfired==false)
				{
					if(turn==0)
					{
						p_x1=50+(39*cos(angle1));
						p_y1=650+(39*sin(angle1));
						shells.push_back(new hellfire(al_load_bitmap("shell.png"),p_x1,p_y1,50,650,angle1,p1vel,tank2_x,tank_y));
						shellfired=true;
					}
					if(turn==1)
					{
						p_x2=1200+24+39*cos(angle2);
						p_y2=650+10+5*sin(angle2);
						shells.push_back(new hellfire(al_load_bitmap("shell.png"),p_x2,p_y2,1200,650,angle2,p2vel,tank1_x,tank_y));
						shellfired=true;
					}
					turn=(turn+1)%2;
				}
			}
		}
    }

    void world::advance_by_time(double dt)
	{
		for(int i=0;i<bird.size();i++)
			bird[i]->advance_by_time(dt);
    	for(int i=0;i<tanks.size();i++)
    		tanks[i]->advance_by_time(dt);
		for(int i=0;i<shells.size();i++)
			shells[i]->advance_by_time(dt);
		for(int i=0;i<mexplosions.size();i++)
			mexplosions[i]->advance_by_time(dt);
		for(int i=0;i<hexplosions.size();i++)
			hexplosions[i]->advance_by_time(dt);
		for(int i=0;i<shells.size();i++)
		{
			if(shells[i]->hit_ground()==true && shells[i]->hit_target()==false)
			{
				//cout<<"NOT HIT"<<endl;
				int x=shells[i]->get_x();
				int y=shells[i]->get_y();
				shells.pop_back();
				mexplosions.push_back(new missed(al_load_bitmap("Miss_Explosion.png"),1280,720,x,y));
				//explosion_on=true;
				shellfired=false;
			}
			if(shells[i]->hit_ground()==true && shells[i]->hit_target()==true)
			{
				//cout<<"HIT TANK"<<endl;
				if(turn==0)
					tanks.erase(tanks.begin());
				else
					tanks.erase(tanks.begin()+1);
				int x=shells[i]->get_x();
				int y=shells[i]->get_y();
				shells.pop_back();
				hexplosions.push_back(new hit(al_load_bitmap("Hit_Explosion.png"),1280,720,x,y));
				explosion_on=true;
				gameover=true;
			}
		}
    }

    void world::draw(ALLEGRO_DISPLAY *display)
	{
		p1_vel_ss.str("");
		p1_vel_ss<<"Velocity: "<<p1vel;
		p1_vel_s=p1_vel_ss.str();
		p2_vel_ss.str("");
		p2_vel_ss<<"Velocity: "<<p2vel;
		p2_vel_s=p2_vel_ss.str();
		p1_theta_ss.str("");
		p1_theta_ss<<"Turret Angle: "<<angle1;
		p1_theta_s=p1_theta_ss.str();
		p2_theta_ss.str("");
		p2_theta_ss<<"Turret Angle: "<<angle2;
		p2_theta_s=p2_theta_ss.str();
    	al_draw_bitmap(background, 0, 0, 0);
		for(int i=0;i<bird.size();i++)
			bird[i]->draw(display);
    	for(int i=0;i<tanks.size();i++)
    		tanks[i]->draw(display);
		for(int i=0;i<shells.size();i++)
			if(shells[i]->hit_ground()==false)
				shells[i]->draw(display);
		for(int i=0;i<mexplosions.size();i++)
		{
				mexplosions[i]->draw(display);
				explosion_on=false;
		}
		for(int i=0;i<hexplosions.size();i++)
		{
			hexplosions[i]->draw(display);
		}
		if(gameover==true)
		{
			al_draw_text(font_70,al_map_rgb(0,0,0),475,60,0,"GAME OVER");
			if(turn==1)
				al_draw_text(font_70,al_map_rgb(0,0,0),400,120,0,"PLAYER 1 WINS!");
			else
				al_draw_text(font_70,al_map_rgb(0,0,0),400,120,0,"PLAYER 2 WINS!");
		}
		al_draw_text(font_20,al_map_rgb(0,0,0),0,0,0,p1_theta_s.c_str());
		al_draw_text(font_20,al_map_rgb(0,0,0),1120,0,0,p2_theta_s.c_str());
		al_draw_textf(font_20,al_map_rgb(0,0,0),0,20,0,p1_vel_s.c_str());
		al_draw_textf(font_20,al_map_rgb(0,0,0),1170,20,0,p2_vel_s.c_str());
		if(turn==0)
			al_draw_text(font_70,al_map_rgb(0,0,0),400,0,0,"Player 1's Turn");
		else
			al_draw_text(font_70,al_map_rgb(0,0,0),400,0,0,"Player 2's Turn");
    }
}
