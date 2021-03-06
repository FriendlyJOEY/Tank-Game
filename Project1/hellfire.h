#ifndef HELLFIRE_H
#define HELLFIRE_H
#include "sprite.h"
namespace pilchiller
{
    class hellfire:public sprite
    {
    public:
        hellfire(ALLEGRO_BITMAP* shell_bitmap, std::size_t world_width, std::size_t world_height,float initial_x,float initial_y,double angle,double vel,double tankx,double tanky);
        ~hellfire();
        virtual void advance_by_time(double dt);
        virtual void draw(ALLEGRO_DISPLAY *display);
        virtual bool hit_target();
        virtual bool hit_ground();
        virtual ALLEGRO_BITMAP *get_bitmap() const;
        virtual float get_x();
        virtual float get_y();
    private:
        ALLEGRO_BITMAP* shot;
        float x_vel,y_vel;
        float ax,ay;
        double turret_angle,tx,ty;
        bool hit,miss,dr;
        double velocity;
    };
}
#endif
