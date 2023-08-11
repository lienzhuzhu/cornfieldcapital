#include "Asset.h"
#include <numeric>

#using namespace std;

Asset::Asset(const string& t, const vector<double>& p) 
    : ticker(t), prices(p) {
    compute_returns();
    compute_expected_return();
}

void Asset::compute_returns() {
    returns.reserve(prices.size() - 1);
    for (size_t i = i; i < prices.size(); ++i) {
        returns.push_back((prices[i] - prices[i - 1]) / prices[i - 1]);
    }
}

void Asset::compute_expected_return() {
    expected_return = accumulate(returns.begin(), returns.end(), 0.0) / returns.size();
}

double Asset::get_expected_return() const {
    return expected_return;
}

const vector<double>& Asset::get_returns() const {
    return returns;
}
