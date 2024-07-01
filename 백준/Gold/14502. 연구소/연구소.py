import sys
from itertools import combinations
import sys

sys.setrecursionlimit(10**7)

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]
n, m = map(int, sys.stdin.readline().split())
lab = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

empty = []
for r in range(n):
    for c in range(m):
        if lab[r][c] == 0:
            empty.append([r, c])


def check(r, c, visited):
    if r < 0 or r >= n or c < 0 or c >= m: return 0
    if lab[r][c] == 1: return 0
    if visited[r][c]: return 0
    
    visited[r][c] = True
    
    result = 1 if lab[r][c] == 0 else 0
    for dr, dc in direction:
        result += check(r + dr, c + dc, visited)
    
    return result


def calc_safe_area():
    safe = len(empty) - 3
    visited = [[False] * m for _ in range(n)]
    
    for r in range(n):
        for c in range(m):
            if lab[r][c] == 2 and not visited[r][c]:
                safe -= check(r, c, visited)
    
    return safe
    

answer = 0
for a, b, c in combinations(empty, 3):
    r1, c1 = a
    r2, c2 = b
    r3, c3 = c
    
    lab[r1][c1] = 1
    lab[r2][c2] = 1
    lab[r3][c3] = 1
    
    answer = max(answer, calc_safe_area())
    
    lab[r1][c1] = 0
    lab[r2][c2] = 0
    lab[r3][c3] = 0

print(answer)