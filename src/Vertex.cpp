



#include "Vertex.hpp"



Vertex::Vertex(Vec3 p) :
      pos(p),
      nml(),
//         edge_list(),
      col(al_map_rgba(255,255,255,255)) 
{}
Vertex::Vertex(Vec3 p , ALLEGRO_COLOR c) :
      pos(p),
      nml(),
//         edge_list(),
      col(c)
{}
Vertex::Vertex(Vec3 p , Vec3 n , ALLEGRO_COLOR c) :
      pos(p),
      nml(n),
//         edge_list(),
      col(c)
{}


