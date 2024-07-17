import sys

n = int(sys.stdin.readline())
dp = [[0, 1] for _ in range(n)]
# dp[i][0] = i번째 자리가 0인 개수
# dp[i][1] = i번째 자리가 1인 개수
for i in range(1, n):
    dp[i][0] = sum(dp[i - 1])
    dp[i][1] = dp[i - 1][0]

print(sum(dp[n - 1]))