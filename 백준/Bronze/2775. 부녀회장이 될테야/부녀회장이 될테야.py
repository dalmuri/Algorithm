import sys

t = int(sys.stdin.readline())
for _ in range(t):
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    
    dp = [[0] * (n + 1) for i in range(k + 1)]
    dp[0] = list(range(n + 1))
    
    for i in range(1, k + 1):
        for j in range(1, n + 1):
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
    
    print(dp[k][n])