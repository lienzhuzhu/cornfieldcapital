#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include "Asset.h"

class Portfolio {
public:
    Portfolio();
    std::vector<Asset> assets;
    
    double calculate_expected_return();
    double calculate_variance();

};

#endif // PORTFOLIO_H
