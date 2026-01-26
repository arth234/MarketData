#include <vector>
#include <sqlite3.h>
#include "constconcepts.h"
#include "marketdata.h"
#include "index.h"

using namespace std;

template <typename engulfing>

engulfing indicator(engulfing a)
{
  return a;
}

auto engulfingEncapsulating()
{
  ConstConcepts i;
 
  size_t alpha;

  if(((i.net(3)/3) < 0) &&
  (i.body(4) < i.body(5)))
  {
    indicator(alpha++)
  } 
}

