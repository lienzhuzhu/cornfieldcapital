#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>

class Portfolio {
public:
    std::vector<Asset> assets;
    
    double calculateExpectedReturn();
    double calculateVariance();

};

#endif // PORTFOLIO_H
