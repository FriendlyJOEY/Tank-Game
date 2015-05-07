#ifndef BIRDS_H
#define BIRDS_H
#include <cmath>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
#include <cstdlib>

namespace pilchiller
{
    class birds
    {
    public:
        birds(ALLEGRO_BITMAP* initial_bitmap, std::size_t world_width, std::size_t world_height, float initial_x, float initial_y, float initial_vx = 0, float initial_vy = 0);
        ~birds();
        void draw(ALLEGRO_DISPLAY *display);
        void advance_by_time(double dt);
    private:
        int x;
        float x_pos;
        float y_pos;
        float x_v;
        float y_v;
        ALLEGRO_BITMAP* bitmap;
    };
}
#endif /* SPRITE_H */
