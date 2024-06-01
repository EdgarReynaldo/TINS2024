



#ifndef Track_HPP
#define Track_HPP

#include "Prism.hpp"
#include "SpatialInfo.hpp"
#include "CrossSection.hpp"
#include "CrossSectionGen.hpp"

#include <memory>
#include <vector>



class TrackInfo {
   
protected :
   SpatialInfo info;
   CrossSection csection;
public :
   
///   TrackInfo();
   TrackInfo() :
         info(START),
         csection()
   {}
   TrackInfo(const SpatialInfo& spatial_info , const CrossSection& cross_section);
   void Set(const SpatialInfo& spatial_info , const CrossSection& cross_section);
   
   SpatialInfo Info()      const {return info;}
   Vec3 Pos()              const {return info.pos;}
   Orient Orientation()    const {return info.orient;}
   double Width()          const {return csection.Width();}
   CrossSection CSection() const {return csection;}
   
};

class TrackSegmentBase {
   
protected :
   TrackInfo start;
public :
   TrackSegmentBase() : start() {}
   virtual ~TrackSegmentBase() {}
   
   void SetStart(const TrackInfo& info) {start = info;}

   virtual SpatialInfo Eval(double dt)=0;
   
   virtual double Length()=0;
};




template <class TGENERATOR>
class TSG : public TrackSegmentBase {
   
protected :
   TGENERATOR tg;
   double length;

public :
//   TSG(GENERATOR generator);
   
   TSG(TGENERATOR tgenerator) : 
         TrackSegmentBase(),
         tg(tgenerator),
         length(tgenerator.Length())
   {}
   
   SpatialInfo Eval(double dt);
   
   double Length() {return length;}
};





template<class TGENERATOR>
SpatialInfo TSG<TGENERATOR>::Eval(double dt) {
//   SpatialInfo info = tg.Eval(start.info , dt);
//   CrossSection cs = csg.Eval(start.csection , dt);
   return tg.Eval(start.Info() , dt);
}






class TrackSegment {
   
protected :
   std::shared_ptr<TrackSegmentBase> pgen;
   
public :
   TrackSegment(TrackSegmentBase* tbase) : pgen(tbase) {}
   
   void SetStart(const TrackInfo& tinfo) {pgen->SetStart(tinfo);}

   SpatialInfo Eval(double dt) {return pgen->Eval(dt);}
   
   double Length() {return pgen->Length();}
   
};



class Track {

protected :
   
   TrackInfo start;
   Prism bounds;
   double length;
   
   Mesh uppermesh;
   Mesh lowermesh;
   Mesh leftmesh;
   Mesh rightmesh;
   Mesh frontmesh;
   Mesh backmesh;
   
   std::vector<TrackSegment> segments;
   std::vector<CSG> csgenerators;
   std::vector<TrackInfo> track;

   ALLEGRO_BITMAP* trackbmp;
   
   
   
   SpatialInfo GetRealInfoFromLocal(const SpatialInfo& info , const Vec2& csxy , const double& roll);

   void ClearMeshes();
   double CalcLength();
   

   bool GenerateTrack(double dz);
   
   bool GenerateTrackMesh();
   
   Prism GetBoundingPrism();

public :
   
///   Track();
   
   Track() :
         start(),
         bounds(),
         uppermesh(),
         lowermesh(),
         leftmesh(),
         rightmesh(),
         frontmesh(),
         backmesh(),
         segments(),
         csgenerators(),
         track(),
         trackbmp(0)
   {
      trackbmp = al_load_bitmap("Data/Textures/CobbleStone1024.png");
   }
   
   ~Track() {al_destroy_bitmap(trackbmp);}
   
   void AddSegment(TrackSegment seg , CSG csgenerator);
   
   bool BuildTrack();
   
   void Draw();
   void DrawOutlines();
   
   const std::vector<TrackInfo>& TrackInfoVec() const {return track;}
   double Length() {return length;}
   
   const Prism& Bounds() const {return bounds;}
};



#endif // Track_HPP





