#include "Asset.h"
#include <numeric>

using namespace std;

Asset::Asset(string& t, vector<double>& p) 
    : ticker(t), prices(p) {
    compute_returns();
    compute_expected_return();
}

void Asset::compute_returns() {
    returns.reserve(prices.size() - 1);
    for (size_t i = 1; i < prices.size(); ++i) {
        returns.push_back((prices[i] - prices[i - 1]) / prices[i - 1]);
    }
}

void Asset::compute_expected_return() {
    expected_return = accumulate(returns.begin(), returns.end(), 0.0) / returns.size();
}

double Asset::get_expected_return() {
    return expected_return;
}

vector<double> Asset::get_returns() {
    return returns;
}

std::string Asset::get_ticker() {
    return ticker;
}
