#ifndef WORLD_H
#define WORLD_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "missed.h"
#include "hit.h"
#include "hellfire.h"
#include "sprite.h"
#include "Tank.h"
#include "birds.h"
#include <vector>
#include <sstream>
#include <cstring>

namespace pilchiller
{
  class world
  {
  public:
    /**
     * Construct the world. The display is passed in simply to make it
     * possible to modify options or access the backbuffer. DO NOT
     * store the display in an instance variable. DO NOT start drawing
     * on the screen. Just load bitmaps etc.
     */
    world(ALLEGRO_DISPLAY *display, std::size_t window_width, std::size_t window_height);

    /**
     * Free any resources being used by the world.
     */
    ~world();

    /**
     * Block the copy constructor.  Worlds should not be copied to
     * just assert(false)
     */
    world(const world& other);

    /**
     * Block operator =.  Worlds should not be assigned.
     */
    world& operator =(const world& other);

    /**
     * Update the state of the world based on the event ev.
     */
    void handle_event(ALLEGRO_EVENT ev);

    /**
     * Advance the state of the world forward by the specified time.
     */
    void advance_by_time(double dt);

    /**
     * Draw the world. Note that the display variable is passed only
     * because it might be needed to switch the target bitmap back to
     * the backbuffer.
     */
    void draw(ALLEGRO_DISPLAY *display);

  private:
  	ALLEGRO_BITMAP* background;
    ALLEGRO_FONT *font_20,*font_70;
  	float width,height;
  	int turn;
    double tank1_x,tank2_x,tank_y;
  	std::vector<Tank*> tanks;
    std::vector<hellfire*> shells;
    std::vector<missed*> mexplosions;
    std::vector<hit*> hexplosions;
    std::vector<birds*> bird;
    double angle1,angle2;
    float p_x1,p_x2,p_y1,p_y2;
    bool shellfired;
    bool explosion_on,gameover;
    double p1vel,p2vel;
    std::stringstream p1_vel_ss,p2_vel_ss,p1_theta_ss,p2_theta_ss;
    std::string p1_vel_s,p2_vel_s,p1_theta_s,p2_theta_s;
  };
}

#endif /* WORLD_H */
