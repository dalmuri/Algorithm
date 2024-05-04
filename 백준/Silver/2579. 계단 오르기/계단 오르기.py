import sys

n = int(sys.stdin.readline())
stair = []
for _ in range(n):
    stair.append(int(sys.stdin.readline()))

dp = [[0, 0] for _ in range(n)]
# dp[i][0] = stair[i]를 이전 계단과 연속하지 않고 밟을 때의 점수 최댓값
# dp[i][1] = stair[i]를 이전 계단과 연속해서 밟을 때의 점수 최댓값
dp[0] = [stair[0], stair[0]]

if n == 1:
    print(stair[0])
else:
    dp[1][0] = stair[1]
    dp[1][1] = stair[0] + stair[1]
    
    for i in range(2, n):
        dp[i][0] = max(dp[i - 2]) + stair[i]
        dp[i][1] = dp[i - 1][0] + stair[i]
    
    print(max(dp[n - 1]))