



#ifndef Tri3_HPP
#define Tri3_HPP


#include "Vec3.hpp"

class Mesh;


class Tri3 {
   
   unsigned int v1,v2,v3;
   unsigned int e1,e2,e3;
   unsigned int n1,n2,n3;
/**
   Mesh* mesh;
   
   const Vec3& Point1() const {return mesh->Point(v1);}
   const Vec3& Point2() const {return mesh->Point(v2);}
   const Vec3& Point3() const {return mesh->Point(v3);}
   
   const Edge& Edge1() const {return mesh->Edge(e1);}
   const Edge& Edge2() const {return mesh->Edge(e2);}
   const Edge& Edge3() const {return mesh->Edge(e3);}
   
   Normal();/// uses ccw winding
   Vec3 Normal() {
      Vec3 p1p2 = Point2() - Point1();
   }
*/
};

#endif // Tri3_HPP

