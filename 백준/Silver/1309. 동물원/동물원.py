import sys

n = int(sys.stdin.readline())
mod = 9901

dp = [[0, 0] for _ in range(n)]
# dp[i][0] = [0, i] 구간에서 동물원[i][0]에 사자를 넣을 때 가능한 개수
#            [0, i] 구간에서 동물원[i][1]에 사자를 넣을 때의 개수도 동일하므로 따로 구하지 않음
# dp[i][1] = [0, i] 구간에서 동물원[i][0], 동물원[i][1]에 모두 사자를 넣지 않을 때 가능한 개수
dp[0][0] = 1
dp[0][1] = 1

for i in range(1, n):
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod
    dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % mod

print((dp[n - 1][0] * 2 + dp[n - 1][1]) % mod)