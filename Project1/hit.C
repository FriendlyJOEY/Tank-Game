#include "hit.h"
#include "sprite.h"
namespace pilchiller
{
    hit::hit(ALLEGRO_BITMAP* hit_expl,std::size_t world_width, std::size_t world_height, float initial_x, float initial_y):sprite(world_width,world_height,initial_x, initial_y)
    {
        x_pos=initial_x;
        y_pos=initial_y;
        h_explosion=hit_expl;
        count=3000;
    }

    hit::~hit()
    {

    }

    void hit::draw(ALLEGRO_DISPLAY *display){
        al_draw_bitmap(h_explosion,x_pos,y_pos,0);
    }

    void hit::advance_by_time(double dt){
        count-=(dt);
    }
}
