#include <vector>
#include <cmath>
#include "marketdata.h"
#include "INDEX.h"
#include "ConstConcepts.h"

double Concepts::Body(size_t i)
{
  return std::abs(
  period[getIn(i)].close -
  period[getIn(i)].open);
}

double Concepts::LowerShadow(size_t i)
{
  double net =
  period[getIn(i)].close -
  period[getIn(i)].open;

  return net < 0
  ? std::abs(period[getIn(i)].close - period[getIn(i)].low)
  : std::abs(period[getIn(i)].open  - period[getIn(i)].low);
 }

  
double Concepts::UpperShadow(size_t i)
{
  double net =
  period[getIn(i)].close -
  period[getIn(i)].open;

  return net < 0
  ? std::abs(period[getIn(i)].open  - period[getIn(i)].high)
  : std::abs(period[getIn(i)].close - period[getIn(i)].high);
}

