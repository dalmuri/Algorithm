import sys

n = int(sys.stdin.readline())
prices = [0] + list(map(int, sys.stdin.readline().split()))

dp = [0] * (n + 1)
for i in range(n + 1):
    for p in range(1, n + 1):
        if i + p > n: break
        dp[i + p] = max(dp[i + p], dp[i] + prices[p])

print(dp[n])