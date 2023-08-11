#ifndef ASSET_H
#define ASSET_H

#include <vector>
#include <string>

class Asset {
private:
    std::string ticker;
    std::vector<double> prices; // daily prices on close
    std::vector<double> returns;
    double _expected_return;

public:
    Asset(const std::string&, const std::vector<double>&);

    void compute_returns();
    void compute_expected_return();

    double get_expected_return() const;
    const std::vector<double>& get_returns() const;
};

#endif // ASSET_H
