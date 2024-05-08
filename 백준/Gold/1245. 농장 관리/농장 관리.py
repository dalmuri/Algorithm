import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())

direction = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

farm = []
for _ in range(n):
    farm.append(list(map(int, sys.stdin.readline().split())))

visited = [[False] * m for _ in range(n)]
def check(r, c, height):
    visited[r][c] = True
    result = True
    for dr, dc in direction:
        nr = r + dr
        nc = c + dc
        if nr < 0 or nr >= n or nc < 0 or nc >=m: continue
        if farm[nr][nc] < height: continue
        if farm[nr][nc] > height:
            result = False
            continue
        if visited[nr][nc]: continue
        
        result &= check(nr, nc, height)
    return result
    

answer = 0
for r in range(n):
    for c in range(m):
        if visited[r][c]: continue
        
        if check(r, c, farm[r][c]):
            answer += 1

print(answer)