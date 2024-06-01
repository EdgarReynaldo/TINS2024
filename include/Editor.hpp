



#ifndef Editor_HPP
#define Editor_HPP


#include "Scene.hpp"
#include "Camera.hpp"
#include "Track.hpp"
#include "TrackGen.hpp"
#include "Skybox.hpp"


class Editor : public Scene {

protected :
   Camera cam;
   Track track1;
   Track track2;
   Track track3;
   Track track4;
   Track track5;
   
   double cam_speed;
   double cam_turn_rate;
   
   Skybox skybox;

public :
   
//   Editor();
   Editor();
   
   virtual STATUS HandleEvent(ALLEGRO_EVENT ev);
   virtual void Display();
   virtual STATUS Update(double dt);
};



#endif // Editor_HPP

