import sys
from heapq import heappush, heappop

inf = 100_000
direction = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상 우 하 좌
m, n = map(int, sys.stdin.readline().split())

maze = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(n)]
crash = [[inf] * m for _ in range(n)]

hq = []
heappush(hq, [0, 0, 0])
while hq:
    cnt, r, c = heappop(hq)
    if cnt >= crash[r][c]: continue
    
    crash[r][c] = cnt
    if r == n - 1 and c == m - 1: break
    
    for dr, dc in direction:
        next_r = r + dr
        next_c = c + dc
        if next_r < 0 or next_r >= n or next_c < 0 or next_c >= m: continue
        
        heappush(hq, [cnt + maze[next_r][next_c], next_r, next_c])

print(crash[n - 1][m - 1])