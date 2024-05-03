import sys
import math

t = int(sys.stdin.readline())
for _ in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())

    d = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    
    if d > r1 + r2: print(0)
    elif d == r1 + r2: print(1)
    elif d == 0 and r1 == r2: print(-1)
    elif d > max(r1, r2) - min(r1, r2): print(2)
    elif d == max(r1, r2) - min(r1, r2): print(1)
    else: print(0)