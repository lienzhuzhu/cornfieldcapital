#include "stats.h"

using namespace std;


Eigen::MatrixXd compute_covariance_matrix(const vector<Asset>& assets) {
    int num_assets = assets.size();
    Eigen::MatrixXd covariance_matrix(num_assets, num_assets);

    for (int i = 0; i < num_assets; ++i) {
        for (int j = i; j < num_assets; ++j) {
            double cov = compute_covariance(assets[i], assets[j]);
            covariance_matrix(i, j) = cov;
            
            // The matrix is symmetric, reflect across diagonal to fill in the other half
            covariance_matrix(j, i) = cov;
        }
    }
    return covariance_matrix;
}

double compute_covariance(const Asset& asset_1, const Asset& asset_2) {
    const vector<double>& returns_1 = asset_1.get_returns();
    const vector<double>& returns_2 = asset_2.get_returns();

    double mean_1 = asset_1.compute_expected_return();
    double mean_2 = asset_2.compute_expected_return();

    double sum = 0.0;
    for (size_t t = 0; t < returns_1.size(); ++t) {
        sum += (returns_1[t] - mean_1) * (returns_2[t] - mean_2);
    }

    return sum / (returns_1.size() - 1);
}
