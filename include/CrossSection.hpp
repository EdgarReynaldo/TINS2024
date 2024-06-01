



#ifndef CrossSection_HPP
#define CrossSection_HPP



#include <vector>
#include "Vec2.hpp"


class CrossSection {
protected :

   double lateral_width;/// lateral x width of track

   /** pts is a collection of points on the xy plane with up corresponding to up and right corresponding to right */
   std::vector<Vec2> xypts;
   std::vector<double> latdist;
   std::vector<double> rvals;

public :
//   CrossSection(CrossSectionBase* new_cs);
///   CrossSection();
   CrossSection() :
         lateral_width(0.0),
         xypts(),
         latdist(),
         rvals()
   {}
   
   void Clear();

   void AddPoint(Vec2 xy , double roll);
///   void AddPoint(Vec2 xy , double lateral_distance , double roll);
   
   double Width() const {return lateral_width;}
   const std::vector<Vec2>& XYPts() const {return xypts;}
   const std::vector<double>& LatDist() const {return latdist;}
   const std::vector<double>& RollValues() const {return rvals;}
   unsigned int NPTS() const {return xypts.size();}

   /// pct is from [-1.0 , 1.0], represents how far along x - axis we are on the cross section
   Vec2 XYPosition(double xpct) const;
   double LatDist(double xpct) const;
   double RollValue(double xpct) const;


};




#endif // CrossSection_HPP
