#include <fstream>
#include <sstream>
#include <iostream>
#include "data_loader.h"

using namespace std;

vector<double> read_closing_prices_from_csv(const string& file_path) {
    ifstream file(file_path);
    vector<double> closing_prices;

    if (!file.is_open()) {
        cerr << "Failed to open the file: " << file_path << endl;
        return closing_prices;
    }

    string line, token;
    getline(file, line);  // Skip the header row

    while (getline(file, line)) {
        istringstream ss(line);
        string closing_price;
        while (getline(ss, token, ',')) {
            closing_price = token; // Keep updating the closing_price until the last column is read
        }
        try {
            closing_prices.push_back(stod(closing_price)); // Convert string to double
        } catch (const exception& e) {
            cerr << "Error parsing closing price: " << closing_price << " - " << e.what() << endl;
        }
    }
    file.close();
    return closing_prices;
}
