import yfinance as yf
import os

# Ensure the directory exists; if not, create it
if not os.path.exists('stock_data'):
    os.makedirs('stock_data')

def fetch_data(ticker):
    start_date="2010-01-01"
    end_date="2020-12-31"
    data = {}
    
    for ticker in tickers:
        stock_data = yf.download(ticker, start=start_date, end=end_date)
        data[ticker] = stock_data['Close']  # We're only extracting the 'Close' prices for simplicity
    
    return data

# Example usage:
tickers = ["AAPL", "MSFT", "GOOGL", "AMZN", "KO"]  # Example list of stock tickers
data = fetch_data(tickers)

# Save to CSV
for ticker, df in data.items():
    df.to_csv(f"stock_data/{ticker}.csv")
