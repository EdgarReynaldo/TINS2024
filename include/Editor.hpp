



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
   
   double cam_speed;
   double cam_turn_rate;
   
   Skybox skybox;

public :
   
//   Editor();
   Editor();
   
   STATUS HandleEvent(EagleEvent ev) override;
   void Display(EagleGraphicsContext* win) override;
   STATUS Update(double dt) override;
};



#endif // Editor_HPP

