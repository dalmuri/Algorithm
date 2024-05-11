import sys

n = int(sys.stdin.readline())
price = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())

dp = [0] * (m + 1)
for i in reversed(range(n)):
    p = price[i]
    for j in range(p, m + 1):
        dp[j] = max(dp[j], dp[j - p] * 10 + i)

print(dp[m])