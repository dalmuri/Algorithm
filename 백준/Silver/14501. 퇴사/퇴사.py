import sys

n = int(sys.stdin.readline())
works = [[0, 0]] + [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [0] * (n + 1)
for i in range(1, n + 1):
    for j in range(i + works[i][0] - 1, n + 1):
        dp[j] = max(dp[j], dp[i - 1] + works[i][1])

print(dp[n])