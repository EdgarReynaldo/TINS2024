



#ifndef CrossSectionGen_HPP
#define CrossSectionGen_HPP



#include "CrossSection.hpp"
#include "CrossSectionTypes.hpp"

class CSGBase {
protected :
   Curve cstart;
public :
   CSGBase() : cstart(0) {}
   
   virtual ~CSGBase() {}   
//   virtual CrossSection GenCSection(const unsigned int NSEGS)=0;
   void SetStartingCurve(Curve start);
   
   virtual Curve FinishCurve()=0;
   virtual CrossSection Generate(const unsigned int NSEGS , double pct)=0;
};




class CurvedCSG : public CSGBase {
   
protected :
   Curve cfinish;
   
public :
   
   
   CurvedCSG(Curve finish);

   virtual Curve FinishCurve();

   CrossSection Generate(const unsigned int NSEGS , double pct);
};




class CSG {
   std::shared_ptr<CSGBase> csg;

public :
   CSG(CSGBase* csgptr) : csg(csgptr) {}

   void SetStartingCurve(Curve start) {csg->SetStartingCurve(start);}
   
   Curve FinishCurve() {return csg->FinishCurve();}

   CrossSection Generate(const unsigned int NSEGS , double pct) {return csg->Generate(NSEGS , pct);}
};

#endif // CrossSectionGen_HPP




