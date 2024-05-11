import sys

inf = 10**6
c, n = map(int, sys.stdin.readline().split())
city = []
for _ in range(n):
    city.append(list(map(int, sys.stdin.readline().split())))

dp = [inf] * (c + 1) # dp[i] = i명을 늘리기 위해 필요한 비용의 최솟값
dp[0] = 0
for price, customer in city:
    for i in range(c - customer + 1):
        dp[i + customer] = min(dp[i + customer], dp[i] + price)
    for i in range(max(0, c - customer + 1), c):
        dp[c] = min(dp[c], dp[i] + price)

print(dp[c])