



#ifndef CrossSectionTypes_HPP
#define CrossSectionTypes_HPP

#include "CrossSection.hpp"


#include <memory>




class CrossSectionBase {
   
public :
   CrossSectionBase() {}
   virtual ~CrossSectionBase() {}
   
   virtual Vec2 XYPosition(double xpct) const =0;
///   virtual double LatDist(double xpct) const =0;
   virtual double Roll(double xpct) const =0;/// Measures the amount of roll, so we can get the orientation at that point on the cross section
   
   CrossSection Generate(const unsigned int NSEGS);
};





class ArcBase : public CrossSectionBase {

protected :
   double hrad;
   double vrad;
   double tstart;
   double tcenter;
   double twidth;
   double ypos;


   double CalcLength(const unsigned int NSEGS);
   
public :
   
   ArcBase(double hdiameter , double vradius , double ycenter , double theta_width);
   
   virtual Vec2 XYPosition(double xpct) const;
///   virtual double LatDist(double xpct) const;
   virtual double Roll(double xpct) const;
   
   double HDiameter() const {return 2.0*hrad;}
   double HRadius() const {return hrad;}
   double VRadius() const {return vrad;}
   double TWidth() const {return twidth;}
   double YPos() const {return ypos;}
};


/** A ring forms a circle on the xy plane. It's normal is the forward vector. */

class Ring : public ArcBase {

protected :
   double rad;

public :
   Ring(double ycenter , double radius);
};


/** A tunnel is the inside of a ring */

class Tunnel : public Ring { 

public :
   Tunnel(double radius);
};

/** A mound is the outside of a ring */

class Mound : public Ring {

public :
   Mound(double radius);
};


class CurvedSpan : public ArcBase {
   
public :
   /// Arc(double ycenter , double hradius , double vradius , double theta_start , double theta_delta , const unsigned int NSEGS);
   CurvedSpan(double hdiameter , double deltay);
   
};



/** A halfpipe forms an open bowl on the local xy plane from -rad/2,-rad to 0,0 to rad/2 */

class HalfPipe : public CurvedSpan {

public :
   HalfPipe(double hradius , double vradius);
};



/** A halfmound forms an upside down open bowl on the local xy plane from -rad/2,rad to 0,0 to rad/2,rad */

class HalfMound : public CurvedSpan {

public :
   HalfMound(double hradius , double vradius);
};



/** A span spans a straight line on the local x-axis from -w/2 to w/2 */
class Span : public ArcBase {
   double w;
public :
   Span(double width);
   
   virtual Vec2 XYPosition(double xpct) const {return Vec2(xpct*w/2.0 , 0.0);}
   virtual double Roll(double xpct) const {(void)xpct;return 0.0;}
   
};



class Curve {
   
protected :
   std::shared_ptr<ArcBase> pbase;
   
public :
   Curve(ArcBase* base) : pbase(base) {}
      
   
   Vec2 XYPosition(double xpct) const {return pbase->XYPosition(xpct);}
   double Roll(double xpct)     const {return pbase->Roll(xpct);}
   
   CrossSection Generate(const unsigned int NSEGS) const {return pbase->Generate(NSEGS);}

   double HDiameter() const {return pbase->HDiameter();}
   double HRadius() const {return pbase->HRadius();}
   double VRadius() const {return pbase->VRadius();}
   double TWidth() const {return pbase->TWidth();}
   double YPos() const {return pbase->YPos();}
};



#endif // CrossSectionTypes_HPP




