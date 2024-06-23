import sys

x, y, m = map(int, sys.stdin.readline().split())

milk = [False] * (m + 1)
milk[x] = True
milk[y] = True
answer = 0

for i in range(x, m + 1):
    if milk[i]:
        answer = i
        if i + x <= m:
            milk[i + x] = True
        if i + y <= m:
            milk[i + y] = True

print(answer)