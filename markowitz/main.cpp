#include "include/data_loader.h"
#include "include/asset.h"

using namespace std;


int main() {
    string file_path = "/Users/lienzhu/computing/cornfield/data/stock_data/AAPL.csv";
    vector<double> prices = read_closing_prices_from_csv(file_path);
    Asset apple_asset("AAPL", prices);
    // ... other logic
    return 0;
}

