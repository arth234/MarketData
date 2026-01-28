#include <vector>
#include "ConstConcepts.h"
#include "marketdata.h"
#include "INDEX.h"

using namespace std;

template <typename engulfing>

engulfing indicator(engulfing a)
{
  return a;
}

size_t engulfingEncapsulating()
{
  Concepts i;
 
  size_t alpha = 0;

  if(((i.Net(3)/3) < 0) &&
  (i.Body(4) < i.Body(5)))
  {
    return indicator(alpha++);
  }
  else if(((i.Net(3)/3) > 0) &&
  (i.Body(4) < i.Body(5)))
  {
    return indicator(alpha++);
  }
  
  return {} ;
}

