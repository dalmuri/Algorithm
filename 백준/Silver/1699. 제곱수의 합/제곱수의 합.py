import sys
import math

n = int(sys.stdin.readline())
dp = [n + 1] * (n + 1)
dp[0] = 0
for i in range(1, n + 1):
    for d in range(1, int(math.sqrt(i)) + 1):
        dp[i] = min(dp[i], dp[i - d * d] + 1)

print(dp[n])