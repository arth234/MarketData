#include "INDEX.h"
#include "OpenDB.h"
#include "ConstConcepts.h"

Concepts::Concepts(){}

double Concepts::Body(size_t i)
{
  loadCandles();

  if (i >= period.size()) return 0;
    return std::abs(period[getIn(i)].close -
    period[getIn(i)].open);
}

double Concepts::Net(size_t i)
{
  loadCandles();

  if (i >= period.size()) return 0;
    return period[getIn(i)].close -
    period[getIn(i)].open;
}

double Concepts::UpperShadow(size_t i) 
{
  loadCandles();

  if (i >= period.size()) return 0;
    return period[getIn(i)].high -
    std::max(period[getIn(i)].open,
    period[getIn(i)].close);
}

double Concepts::LowerShadow(size_t i) 
{
  loadCandles();

  if (i >= period.size()) return 0;
    return std::min(period[getIn(i)].open,
    period[getIn(i)].close) -
    period[getIn(i)].low;
}

