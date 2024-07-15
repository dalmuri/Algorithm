import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [0] * n
dp[0] = arr[0]
answer = dp[0]

for i in range(1, n):
    dp[i] = max(0, dp[i - 1]) + arr[i]
    answer = max(answer, dp[i])

print(answer)