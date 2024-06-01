



#ifndef Vertex_HPP
#define Vertex_HPP


#include "allegro5/allegro.h"

#include "Vec3.hpp"




class Vertex {

///   void CalcNormal();
///   void CalcNormal() {}
public :
   
   Vertex(Vec3 p);
   Vertex(Vec3 p , EagleColor c);
   Vertex(Vec3 p , Vec3 n , EagleColor c);

   
   Vec3 pos;
   Vec3 nml;
   Vec2 uv;
//   std::vector<unsigned int> edge_list;
   EagleColor col;
};



typedef Vertex VERTEX;



#endif // Vertex_HPP





