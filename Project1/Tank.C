#include "Tank.h"
#include "sprite.h"
namespace pilchiller
{
    Tank::Tank(ALLEGRO_BITMAP* base_bitmap,ALLEGRO_BITMAP* turret_bitmap,double angle, std::size_t world_width, std::size_t world_height, float initial_x, float initial_y) : sprite(world_width, world_height, initial_x, initial_y)
    {
        base=base_bitmap;
        turret=turret_bitmap;
        turret_angle=-.5;
    }

    void Tank::draw(ALLEGRO_DISPLAY *display)
    {
        al_draw_rotated_bitmap(turret,0,10,x_pos+28,y_pos+10,turret_angle,0);
        al_draw_bitmap(base,x_pos,y_pos,0);
    }

    void Tank::rotate_turret_up()
    {
        turret_angle=turret_angle-.1;
    }

    void Tank::rotate_turret_down()
    {
        turret_angle=turret_angle+.1;
    }

    void Tank::advance_by_time(double dt)
    {
		al_draw_rotated_bitmap(turret,x_pos,y_pos,x_pos+15,y_pos,1,0);
    }
}
