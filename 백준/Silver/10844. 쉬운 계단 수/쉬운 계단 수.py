import sys

mod = 1_000_000_000
n = int(sys.stdin.readline())
dp = [[0] * 10 for _ in range(n)]
dp[0] = [0] + [1] * 9
for i in range(1, n):
    for num in range(10):
        if num > 0:
            dp[i][num] += dp[i - 1][num - 1]
        if num < 9:
            dp[i][num] += dp[i - 1][num + 1]
        
        dp[i][num] %= mod

print(sum(dp[n - 1]) % mod)