#include "hellfire.h"
#include "sprite.h"
#include <cmath>
#include <iostream>
using namespace std;
namespace pilchiller
{
    hellfire::hellfire(ALLEGRO_BITMAP* shell_bitmap, std::size_t world_width, std::size_t world_height,float initial_x,float initial_y,double angle,double vel,double tankx,double tanky) : sprite(world_width,world_height,initial_x, initial_y)
    {
        tx=tankx;
        ty=tanky;
        shot=shell_bitmap;
        ay=-300;
        ax=0;
        velocity=vel;
        //cout<<turret_angle<<endl;
        turret_angle=angle;
        hit=false;
        miss=false;
        dr=false;
        y_vel=velocity*sin(turret_angle);
        x_vel=velocity*cos(turret_angle);
        x_pos=initial_x;
        y_pos=initial_y;
        //cout<<turret_angle<<endl;
    }
    hellfire::~hellfire()
    {

    }

  ALLEGRO_BITMAP*  hellfire::get_bitmap() const{
    	return shot;
    }

    void hellfire::advance_by_time(double dt)
    {
        y_vel=y_vel+ay*dt;
        x_pos+=x_vel;
        y_pos=y_pos-(y_vel*dt)+ay*dt;
        if(y_pos>ty)
        {
            miss=true;
            if(x_pos>(tx-10) && x_pos<(tx+40))
                hit=true;
        }
    }
    float hellfire::get_x(){
    	return x_pos;
    }
    float hellfire::get_y(){
    	return y_pos;
    }
    void hellfire::draw(ALLEGRO_DISPLAY *display)
    {
        al_draw_bitmap(shot,x_pos,y_pos,0);
    }
    bool hellfire::hit_target()
    {
        return hit;
    }
    bool hellfire::hit_ground()
    {
        return miss;
    }
}
