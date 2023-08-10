#ifndef ASSET_H
#define ASSET_H

#include <vector>

class Asset {
public:
    std::string name;
    std::vector<double> historical_prices;
    std::vector<double> daily_returns;
};

#endif // ASSET_H
