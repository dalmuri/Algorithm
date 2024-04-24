import sys

n, m = map(int, sys.stdin.readline().split())

is_sq = [False] * (m - n + 1)

i = 2
while i*i <= m:
    sq = i * i
    now = (n // sq) * sq - n
    while now <= m - n:
        if now >= 0:
            is_sq[now] = True
        now += sq
    i += 1

print(is_sq.count(False))