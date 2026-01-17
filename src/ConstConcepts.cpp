#include <vector>
#include <cmath>
#include "marketdata.h"
#include "INDEX.h"

class Concepts
{
  public:
    double Body(size_t i)
    {
        return std::abs(
            period[getIn(i)].close -
            period[getIn(i)].open
        );
    }

    double LowerShadow(size_t i)
    {
        double net =
            period[getIn(i)].close -
            period[getIn(i)].open;

        return net < 0
            ? std::abs(period[getIn(i)].close - period[getIn(i)].low)
            : std::abs(period[getIn(i)].open  - period[getIn(i)].low);
    }

    double UpperShadow(size_t i)
    {
        double net =
            period[getIn(i)].close -
            period[getIn(i)].open;

        return net < 0
            ? std::abs(period[getIn(i)].open  - period[getIn(i)].high)
            : std::abs(period[getIn(i)].close - period[getIn(i)].high);
    }

};
