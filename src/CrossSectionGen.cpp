



#include "CrossSectionGen.hpp"
#include "Interpolate.hpp"



void CSGBase::SetStartingCurve(Curve start) {
   cstart = start;
}



CurvedCSG::CurvedCSG(Curve finish) :
      CSGBase(),
      cfinish(finish)
{}



Curve CurvedCSG::FinishCurve() {
   return cfinish;
}



CrossSection CurvedCSG::Generate(const unsigned int NSEGS , double pct) {
   
   if (pct <= 0.0) {return cstart.Generate(NSEGS);}
   if (pct >= 1.0) {return cfinish.Generate(NSEGS);}
   
   double hdiameter = Interpolate(cstart.HDiameter() , cfinish.HDiameter() , pct);
   double vradius   = Interpolate(cstart.VRadius()   , cfinish.VRadius()   , pct);
   double ypos      = Interpolate(cstart.YPos()      , cfinish.YPos()      , pct);
   double awidth    = Interpolate(cstart.TWidth()    , cfinish.TWidth()    , pct);

///   ArcBase(double hdiameter , double vradius , double ycenter , double theta_width);
   ArcBase arc(hdiameter , vradius , ypos , awidth);
   return arc.Generate(NSEGS);
}
