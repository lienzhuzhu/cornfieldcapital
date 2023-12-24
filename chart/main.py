import numpy
import pygame
import math
import time
import argparse

import data_fetcher


def main():
    parser = argparse.ArgumentParser(description="Awesome pixel art stock data visualizer so you can know how jacked you are.")
    parser.add_argument("ticker", help="Stock you would like to visualize", required=True)
    args = parser.parse_args()
    ticker = args.ticker

    data_fetcher.fetch_data(ticker)



if __name__ == "__main__":
    main()
