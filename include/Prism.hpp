



#ifndef Prism_HPP
#define Prism_HPP


#include "Cube.hpp"



class Prism {
   
   UnitCube unitcube;
   
   SpatialInfo info;
   
   double w;
   double h;
   double d;
   
public :
   
//   Prism();
   Prism() :
         unitcube(),
         info(Vec3(0.0,0.0,0.0) , Orient()),
         w(1),
         h(1),
         d(1)
   {}
   
//   Prism(Vec3 center , double width , double height , double depth);
   Prism(Vec3 center , double width , double height , double depth) :
      unitcube(),
      info(center , Orient()),
      w(abs(width)),
      h(abs(height)),
      d(abs(depth))
   {}
   
   inline double Width()  const {return w;}
   inline double Height() const {return h;}
   inline double Depth()  const {return d;}
   
   inline double LeftX()  const {return info.pos.x - w/2.0;}
   inline double RightX() const {return info.pos.x + w/2.0;}
   inline double TopY()   const {return info.pos.y - h/2.0;}
   inline double BotY()   const {return info.pos.y + h/2.0;}
   inline double BackZ()  const {return info.pos.z + d/2.0;}
   inline double FrontZ() const {return info.pos.z - d/2.0;}
   
   inline Vec3 TopLeftBack()   const {return Vec3(LeftX()  , TopY() , BackZ()  );}
   inline Vec3 TopLeftFront()  const {return Vec3(LeftX()  , TopY() , FrontZ() );}
   inline Vec3 TopRightBack()  const {return Vec3(RightX() , TopY() , BackZ()  );}
   inline Vec3 TopRightFront() const {return Vec3(RightX() , TopY() , FrontZ() );}
   inline Vec3 BotLeftBack()   const {return Vec3(LeftX()  , BotY() , BackZ()  );}
   inline Vec3 BotLeftFront()  const {return Vec3(LeftX()  , BotY() , FrontZ() );}
   inline Vec3 BotRightBack()  const {return Vec3(RightX() , BotY() , BackZ()  );}
   inline Vec3 BotRightFront() const {return Vec3(RightX() , BotY() , FrontZ() );}
   
   inline void SetCenter(Vec3 c) {info.pos = c;}
   inline void SetInfo(SpatialInfo i) {info = i;}
   
   inline Vec3 Center() const {return info.pos;}
   inline SpatialInfo Info() const {return info;}
   
   inline const Mesh& GetMesh() const {return unitcube.GetMesh();}
};




#endif // Prism_HPP
