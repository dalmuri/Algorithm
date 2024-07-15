import sys

n, k = map(int, sys.stdin.readline().split())
items = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [[0] * (k + 1) for _ in range(n)] # dp[i][j] = items[0:i+1] 중 선택해 담아 배낭의 무게가 j일 때의 최대 가치
dp[0] = [0] * items[0][0] + [items[0][1]] * (k + 1 - items[0][0])
for i in range(1, n):
    w = items[i][0]
    v = items[i][1]
    for j in range(k + 1):
        dp[i][j] = dp[i - 1][j]
        if j - w < 0: continue
        
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v)

print(dp[n - 1][k])