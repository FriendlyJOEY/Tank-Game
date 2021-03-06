#ifndef SPRITE_H
#define SPRITE_H
#include "allegro5/allegro.h"
#include <cstdlib>

namespace pilchiller {
  class sprite {
  public:
    /**
     * Construct a sprite giving it a bitmap to display when it is
     * drawn and the position of its upper-left hand corner in the
     * world.  Also specify the initial velocity of the sprite.
     */
    sprite(std::size_t world_width, std::size_t world_height, float initial_x, float initial_y);

    /**
     * Destructor
     */
    ~sprite();

    /**
     * these two should cause errors, no copying!
     */
    sprite(const sprite& other);
    sprite& operator =(const sprite& other);


    /**
     * Draw this sprite. See world.draw for discussion of the display
     * variable.
     */
    virtual void draw(ALLEGRO_DISPLAY *display);


    /**
     * Move time forward by the specified amount
     */
    virtual void advance_by_time(double dt);

    /**
     * Return my bitmap
     */
    ALLEGRO_BITMAP *get_bitmap() const;



    // Add other methods here


protected:
	float x_pos,y_pos;
	float height,width;
	ALLEGRO_BITMAP* bitmap;
    // Put your i-vars here

  };
}
#endif /* SPRITE_H */
