



#ifndef WidthGen_HPP
#define WidthGen_HPP



#error UNUSED

/**
#include <memory>

class WidthGeneratorBase {
protected :
   double swidth;///starting width
public :   
   WidthGeneratorBase(double start_width) : swidth(start_width) {}
   
   virtual double EvalWidth(double pct)=0;
};



class WidthGenerator {
protected :
   std::shared_ptr<WidthGeneratorBase> genptr;
   
public :
   WidthGenerator(WidthGeneratorBase* pwgen) : genptr(pwgen) {}
   
   double EvalWidth(double pct) {return genptr->EvalWidth(pct);}
};



class LinearWidthGenerator : public WidthGeneratorBase {
   
   double ewidth;
public :
   LinearWidthGenerator(double start_width , double end_width);
   double EvalWidth(double pct);
};


*/


#endif // WidthGen_HPP
