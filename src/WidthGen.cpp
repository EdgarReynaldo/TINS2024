

/**
#include "WidthGen.hpp"




LinearWidthGenerator::LinearWidthGenerator(double start_width , double end_width) :
      WidthGeneratorBase(start_width),
      ewidth(end_width)
{}



double LinearWidthGenerator::EvalWidth(double pct) {
   if (pct <= 0.0) {return swidth;}
   if (pct >= 1.0) {return ewidth;}
   return swidth + (ewidth - swidth)*pct;
}



*/
