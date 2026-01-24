#include <vector>
#include "marketdata.h"
#include "INDEX.h"
#include "ConstConcepts.h"

Concepts i;


double usual_rangeContracts(double contracts)
{
  bool patternval[4];

  bool net;
  net = (period[getIn(5)].close - 
  period[getIn(5)].open) < 0;

  patternval[1] = (i.body(4) && i.body[1]) <
  ((i.body() + i.body()) /
  period.size());

  patternval[2] = ((patternval[1]) && net);

  return contracts * 1.50;
    
}
