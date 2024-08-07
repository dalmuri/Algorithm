import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

dp = [1] * n
answer = 1
for i in range(1, n):
    for j in range(i):
        if a[j] <= a[i]: continue
        dp[i] = max(dp[i], dp[j] + 1)
    
    answer = max(answer, dp[i])

print(answer)