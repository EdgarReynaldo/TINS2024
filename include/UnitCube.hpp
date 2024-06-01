



#ifndef Cube_HPP
#define Cube_HPP


#include "Vec3.hpp"


#include "Mesh.hpp"



class UnitCube {
   Mesh cube;

   void CreateMesh();
   
public :
   UnitCube();
   
   inline const Mesh& GetMesh() const {return cube;}
   
};


enum CUBE_FACE {
   CUBE_FACE_LEFT   = 0,
   CUBE_FACE_RIGHT  = 1,
   CUBE_FACE_TOP    = 2,
   CUBE_FACE_BOTTOM = 3,
   CUBE_FACE_BACK   = 4,
   CUBE_FACE_FRONT  = 5,
   NUM_CUBE_FACES   = 6
};

enum FACE_CORNER {
   FACETL = 0,
   FACEBL = 1,
   FACEBR = 2,
   FACETR = 3,
   NUM_FACE_CORNERS = 4
};

class TexturedUnitCube {
   Mesh cubeinside;
   Mesh cubeoutside;

   ALLEGRO_BITMAP* textures[NUM_CUBE_FACES];

   void CreateTexturedMesh();

   void Clear();
public :
   
   TexturedUnitCube();
   
   void Texture(ALLEGRO_BITMAP* tex[NUM_CUBE_FACES]);
   
   const Mesh& Inside() {return cubeinside;}
   const Mesh& Outside() {return cubeoutside;}
};


#endif // Cube_HPP
