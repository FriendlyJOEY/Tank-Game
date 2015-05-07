#include <cmath>
#include "birds.h"
#include "world.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include <cstdlib>
namespace pilchiller
{
    birds::birds(ALLEGRO_BITMAP* initial_bitmap, std::size_t world_width, std::size_t world_height, float initial_x, float initial_y, float initial_vx, float initial_vy)
    {
        bitmap=initial_bitmap;
        x_pos=initial_x;
        y_pos=initial_y;
        x_v=initial_vx;
        y_v=initial_vy;
    }
    birds::~birds()
    {

    }
    void birds::draw(ALLEGRO_DISPLAY *display)
    {
        al_draw_bitmap(bitmap,x_pos,y_pos,0);
    }
    void birds::advance_by_time(double dt)
    {
        if(x_pos<1280)
            x_pos+=x_v;
        else
            x_pos=0;
        if(y_pos>0)
            y_pos-=y_v;
        else
            y_pos=720;
            //y_pos=sin(x)*720;
    }
}
