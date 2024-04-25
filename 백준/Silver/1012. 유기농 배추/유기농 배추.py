import sys
from heapq import heappush, heappop

sys.setrecursionlimit(10**6)
direction = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상 우 하 좌

def visit(r, c, n, m, visited, farm):
    if r < 0 or r >= n: return
    if c < 0 or c >= m: return
    if farm[r][c] == 0: return
    if visited[r][c]: return
    
    visited[r][c] = True
    
    for dr, dc in direction:
        visit(r + dr, c + dc, n, m, visited, farm)

t = int(sys.stdin.readline())

for _ in range(t):
    m, n, k = map(int, sys.stdin.readline().split())
    farm = [[0] * m for i in range(n)]
    visited = [[False] * m for i in range(n)]
    
    for i in range(k):
        c, r = map(int, sys.stdin.readline().split())
        farm[r][c] = 1
    
    answer = 0
    for r in range(n):
        for c in range(m):
            if farm[r][c] == 1 and not visited[r][c]:
                answer += 1
                visit(r, c, n, m, visited, farm)
    
    print(answer)