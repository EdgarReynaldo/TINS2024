



#ifndef Mesh_HPP
#define Mesh_HPP

#include "Vertex.hpp"
#include "Texture.hpp"
#include "Orient.hpp"
#include "SpatialInfo.hpp"



#include <vector>

extern const int BAD_INDEX;

extern const unsigned int BAD_VERTEX;
extern const unsigned int BAD_TEXTURE;
extern const unsigned int BAD_NORMAL;



class Edge {
public :
   Edge(unsigned int from , unsigned int to);
   unsigned int vfrom;
   unsigned int vto;
};
typedef Edge EDGE;



class TriFace {
public :
   TriFace(unsigned int i1 , unsigned int i2 , unsigned int i3);

   TriFace(unsigned int i1 , unsigned int i2 , unsigned int i3 ,
           unsigned int ti1 , unsigned int ti2 , unsigned int ti3,
           unsigned int ni1 , unsigned int ni2 , unsigned int ni3);
   unsigned int v1;
   unsigned int v2;
   unsigned int v3;
   unsigned int tv1;
   unsigned int tv2;
   unsigned int tv3;
   unsigned int n1;
   unsigned int n2;
   unsigned int n3;
   
   bool Textured() const;
   bool Normaled() const;
};
typedef TriFace TRIFACE;


typedef Vec3 NORMAL;



class Mesh {
   
protected :
   std::vector<VERTEX> vertices;
   std::vector<NORMAL> normals;
   std::vector<TEXTEX> texverts;

   std::vector<EDGE> edges;
   std::vector<TRIFACE> faces;
   
   unsigned int UnsignedVIndex(int index);
   unsigned int UnsignedTIndex(int index);
   unsigned int UnsignedNIndex(int index);
   
   ALLEGRO_TRANSFORM SetupTransform(const SpatialInfo& info , Vec3 scale) const;
   
   
public :
   
   public :
   
   unsigned int AddVertex(VERTEX v);
   unsigned int AddTexVertex(TEXTEX t);
   unsigned int AddNormal(NORMAL n);

   unsigned int AddEdge(int vfrom , int vto);/// returns the absolute index of the new edge



   /// returns the absolute index of the new triangle face
   unsigned int AddTriFace(int v1 , int v2 , int v3,
                           int n1 = BAD_INDEX , int n2 = BAD_INDEX , int n3 = BAD_INDEX);

   /// returns the absoulte index of the 4 new triangle faces start
   unsigned int AddQuadFace(int vtl , int vbl , int vbr , int vtr,
                            int ntl = BAD_INDEX , int nbl = BAD_INDEX , int nbr = BAD_INDEX , int ntr = BAD_INDEX);

   /// returns the absolute index of the 2 new triangle faces start
   unsigned int AddFlatQuadFace(int vtl , int vbl , int vbr , int vtr,
                                int ntl = BAD_INDEX , int nbl = BAD_INDEX , int nbr = BAD_INDEX , int ntr = BAD_INDEX);
   


   unsigned int AddTexturedTriFace(int v1 , int v2 , int v3 , int tv1 , int tv2 , int tv3 ,
                                   int n1 = BAD_INDEX , int n2 = BAD_INDEX , int n3 = BAD_INDEX);

   unsigned int AddTexturedQuadFace(int vtl , int vbl , int vbr , int vtr,
                                    int vitl , int vibl , int vibr , int vitr ,
                                    int ntl = BAD_INDEX , int nbl = BAD_INDEX , int nbr = BAD_INDEX , int ntr = BAD_INDEX);

   unsigned int AddTexturedFlatQuadFace(int vtl , int vbl , int vbr , int vtr,
                                        int vitl , int vibl , int vibr , int vitr,
                                        int ntl = BAD_INDEX , int nbl = BAD_INDEX , int nbr = BAD_INDEX , int ntr = BAD_INDEX);
   


   inline const VERTEX&  GetVertex   (unsigned int index) {return vertices[index];}
   inline const TEXTEX&  GetTexVertex(unsigned int index) {return texverts[index];}
   inline const NORMAL&  GetNormal   (unsigned int index) {return normals[index];}
   
   inline const EDGE&    GetEdge     (unsigned int index) {return edges[index];}
   inline const TRIFACE& GetTriFace  (unsigned int index) {return faces[index];}
   
   
   void RenderFacesFrontBack    (const SpatialInfo info = SpatialInfo() , const Vec3 scale = Vec3(1,1,1)) const;

   void RenderTexturedFacesFront(const SpatialInfo info = SpatialInfo() , const Vec3 scale = Vec3(1,1,1)) const;

   void RenderFacesFront        (const SpatialInfo info = SpatialInfo() , const Vec3 scale = Vec3(1,1,1)) const;
   void RenderFacesBack         (const SpatialInfo info = SpatialInfo() , const Vec3 scale = Vec3(1,1,1)) const;

   void RenderEdges             (const ALLEGRO_COLOR col , const SpatialInfo info = SpatialInfo() , Vec3 scale = Vec3(1,1,1)) const;

   void ClearAll();
};




#endif // Mesh_HPP






