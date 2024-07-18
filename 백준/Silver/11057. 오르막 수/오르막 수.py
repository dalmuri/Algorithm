import sys

mod = 10007
n = int(sys.stdin.readline())

dp = [[0] * 10 for _ in range(n)]
dp[0] = list(range(1, 11))
for i in range(1, n):
    dp[i][0] = dp[i - 1][0]
    for d in range(1, 10):
        dp[i][d] = (dp[i][d - 1] + dp[i - 1][d]) % mod

print(dp[n - 1][9])