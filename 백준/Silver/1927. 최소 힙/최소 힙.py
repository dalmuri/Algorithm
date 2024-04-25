import sys
from heapq import heappush, heappop

n = int(sys.stdin.readline())
hq = []

for _ in range(n):
    x = int(sys.stdin.readline())
    
    if x == 0:
        if hq:
            print(heappop(hq))
        else:
            print(0)
    else:
        heappush(hq, x)