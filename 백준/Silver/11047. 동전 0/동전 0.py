import sys

n, k = map(int, sys.stdin.readline().split())
coins = [int(sys.stdin.readline()) for _ in range(n)]

answer = 0
for coin in reversed(coins):
    if k >= coin:
        answer += k // coin
        k %= coin

print(answer)