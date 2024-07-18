import sys
import copy

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
dp = copy.deepcopy(a)
answer = dp[0]
for i in range(1, n):
    for j in range(i):
        if a[i] <= a[j]: continue
        dp[i] = max(dp[i], dp[j] + a[i])
    
    answer = max(answer, dp[i])

print(answer)