#ifndef HIT_H
#define HIT_H
#include "sprite.h"
namespace pilchiller
{
    class hit:public sprite
    {
    public:
        hit(ALLEGRO_BITMAP*,std::size_t world_width, std::size_t world_height, float initial_x, float initial_y);
        ~hit();
        virtual void draw(ALLEGRO_DISPLAY *display);
        virtual void advance_by_time(double dt);
    private:
        ALLEGRO_BITMAP* h_explosion;
        double count;
    };
}
#endif
