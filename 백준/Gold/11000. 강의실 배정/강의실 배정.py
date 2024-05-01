import sys
from heapq import heappush, heappop

n = int(sys.stdin.readline())

lesson = []
for _ in range(n):
    lesson.append(list(map(int, sys.stdin.readline().split())))

lesson.sort()
rooms = [lesson[0][1]]
for start, end in lesson[1:]:
    if rooms[0] <= start:
        heappop(rooms)
    heappush(rooms, end)

print(len(rooms))