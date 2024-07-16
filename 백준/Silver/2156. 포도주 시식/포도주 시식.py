import sys

n = int(sys.stdin.readline())
wines = [0] + [int(sys.stdin.readline()) for _ in range(n)]

dp = [[0, 0] for _ in range(n + 1)]
# dp[i][0] = wines[i-1]을 마시지 않고 wines[i]를 마셨을 때의 wines[0:i+1]을 마신 최댓값
# dp[i][1] = wines[i-1], wines[i]를 마셨을 때의 wines[0:i+1]을 마신 최댓값
dp[1] = [wines[1], wines[1]]
if n >= 2: dp[2] = [wines[2], wines[1] + wines[2]]
for i in range(3, n + 1):
    dp[i][0] = max(dp[i - 2][0], dp[i - 2][1], dp[i - 3][0], dp[i - 3][1]) + wines[i]
    dp[i][1] = dp[i - 1][0] + wines[i]

print(max(dp[n - 1][1], dp[n][0], dp[n][1]))