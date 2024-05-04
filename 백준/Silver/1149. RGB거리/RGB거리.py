import sys

n = int(sys.stdin.readline())
cost = [[0, 0, 0]]
for _ in range(n):
    cost.append(list(map(int, sys.stdin.readline().split())))

dp = [[0, 0, 0] for _ in range(n + 1)]
# dp[i][j] = 구간 [0, i]에서 i번의 집을 j색으로 칠할 때 비용의 최솟값

for i in range(1, n + 1):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2]

print(min(dp[n]))