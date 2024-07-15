import sys

n = int(sys.stdin.readline())
mod = 10_007

dp = [0] * max(n + 1, 3)
dp[1] = 1
dp[2] = 2

for i in range(3, n + 1):
    dp[i] = (dp[i - 2] + dp[i - 1]) % mod

print(dp[n])