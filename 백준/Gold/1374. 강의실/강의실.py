import sys
from heapq import heappush, heappop

n = int(sys.stdin.readline())

courses = []
for _ in range(n):
    courses.append(list(map(int, sys.stdin.readline().split())))
courses.sort(key=lambda x: (x[1], x[2]))

rooms = []
for num, start, end in courses:
    if rooms and rooms[0] <= start:
        heappop(rooms)
    heappush(rooms, end)

print(len(rooms))