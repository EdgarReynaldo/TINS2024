



#include "Drawing.hpp"




void OutlinePrism(const Prism& p , ALLEGRO_COLOR c) {
   const Mesh& cubemesh = p.GetMesh();
   
   cubemesh.RenderEdges(c , p.Info() , Vec3(p.Width() , p.Height() , p.Depth()));
}



void DrawTrackOutlines(const Track& track) {
   OutlinePrism(track.Bounds() , al_map_rgb(255,255,255));
   
   Prism p;
   
   const std::vector<TrackInfo>& trackpath = track.TrackInfoVec();
   
   for (unsigned int i = 0 ; i < trackpath.size() - 1 ; ++i) {
         
      p.SetInfo(trackpath[i].Info());
      OutlinePrism(p , al_map_rgb(255,255,255));
         
      Vec3 p1 = trackpath[i].Pos();
      Vec3 p2 = trackpath[i+1].Pos();
      DrawLine(p1 , p2 , al_map_rgb(0,255,255));
   }
}









