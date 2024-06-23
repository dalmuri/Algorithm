import sys

x, y, m = map(int, sys.stdin.readline().split())

milk = [False] * (m + 1)
milk[x] = True
milk[y] = True
answer = y

for i in range(x, m + 1):
    if milk[i]:
        if i + x <= m:
            milk[i + x] = True
            answer = max(answer, i + x)
        if i + y <= m:
            milk[i + y] = True
            answer = max(answer, i + y)

print(answer)