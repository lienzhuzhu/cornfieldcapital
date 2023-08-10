import yfinance as yf

msft = yf.Ticker("MSFT")

print(msft.income_stmt)
print(msft.options)

