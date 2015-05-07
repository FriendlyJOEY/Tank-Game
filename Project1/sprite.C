#include "sprite.h"


namespace pilchiller{
	 sprite::sprite(std::size_t world_width, std::size_t world_height, float initial_x, float initial_y)
	 {
	 	width=world_width;
	 	height=world_height;
	 	x_pos=initial_x;
	 	y_pos=initial_y;
	 }


    sprite::~sprite()
	{

    }


    sprite::sprite(const sprite& other)
	{
    	assert(false);
    }
    sprite& sprite::operator =(const sprite& other)
	{
    	assert(false);
    }


	void sprite::draw(ALLEGRO_DISPLAY *display)
	{
    	al_draw_bitmap(bitmap, x_pos, y_pos, 0);
    }


    void sprite::advance_by_time(double dt)
	{

    }


    ALLEGRO_BITMAP *sprite::get_bitmap() const
	{
    	return bitmap;
    }




}
