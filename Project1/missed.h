#ifndef MISSED_H
#define MISSED_H
#include "sprite.h"
namespace pilchiller
{
    class missed:public sprite
    {
    public:
        missed(ALLEGRO_BITMAP*,std::size_t world_width, std::size_t world_height, float initial_x, float initial_y);
        ~missed();
        virtual void draw(ALLEGRO_DISPLAY *display);
        virtual void advance_by_time(double dt);
    private:
        ALLEGRO_BITMAP* m_explosion;
        double count;
        bool dr;

    };
}
#endif
