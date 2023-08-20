/*
 * Driver for Markowitz Frontier portfolio optimization
 */


#include "include/Asset.h"
#include "include/data_loader.h"
#include "include/stats.h"
#include <iostream>
#include <vector>
#include <filesystem>

void print_vector(const std::vector<double>& vec) {
    for (double val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Directory where CSV files are stored
    std::string directory = "/Users/lienzhu/computing/cornfield/data/stock_data/";

    // Vector to store Asset objects
    std::vector<Asset> assets;

    // Iterate over all CSV files in the directory
    for (const auto &entry : std::filesystem::directory_iterator(directory)) {
        // Load closing prices from the CSV file
        std::string path_string = entry.path().string();
        std::vector<double> prices = read_closing_prices_from_csv(path_string);

        // Extract the ticker name from the filename
        std::string ticker = entry.path().filename().string();
        ticker = ticker.substr(0, ticker.size() - 4);  // Remove ".csv" from the end

        // Create an Asset object
        Asset asset(ticker, prices);
        asset.compute_returns();
        asset.compute_expected_return();

        // Add the Asset object to the assets vector
        assets.push_back(asset);

    }

    // Compute the covariance matrix
    Eigen::MatrixXd cov_matrix = compute_covariance_matrix(assets);

    // Print results
    for (Asset& asset : assets) {
        std::cout << "Ticker: " << asset.get_ticker() 
                  << ", Expected Return: " << asset.get_expected_return() << std::endl;
    }
    std::cout << "\nCovariance Matrix:\n" << cov_matrix << std::endl;

    return 0;
}

