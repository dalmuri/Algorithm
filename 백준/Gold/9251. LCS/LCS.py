import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

dp = [[0] * len(b) for _ in range(len(a))]
idx = b.find(a[0])
if idx != -1:
    for j in range(idx, len(b)):
        dp[0][j] = 1
for i in range(1, len(a)):
    dp[i][0] = 1 if a[i] == b[0] else dp[i - 1][0]
    for j in range(1, len(b)):
        if a[i] == b[j]:
            dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1])
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[-1][-1])