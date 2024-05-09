import sys

n = int(sys.stdin.readline())

works = []
for _ in range(n):
    works.append(list(map(int, sys.stdin.readline().split())))

works.sort(key=lambda x: (-x[1], x[0]))

time = works[0][1]
for work in works:
    time = min(time, work[1])
    time -= work[0]

print(time if time >= 0 else -1)