import sys

n, x = map(int, sys.stdin.readline().split())
prices = list(map(int, sys.stdin.readline().split()))

min_price = prices[0] + prices[1]
for i in range(1, n - 1):
    min_price = min(min_price, prices[i] + prices[i + 1])

print(min_price * x)