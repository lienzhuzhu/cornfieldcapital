#ifndef ASSET_H
#define ASSET_H

#include <vector>
#include <string>

class Asset {
private:
    std::string ticker;
    std::vector<double> prices; // daily prices on close
    std::vector<double> returns;
    double expected_return;

public:
    Asset(std::string&, std::vector<double>&);

    void compute_returns();
    void compute_expected_return();

    double get_expected_return();
    std::vector<double> get_returns();
    std::string get_ticker();
};

#endif // ASSET_H
