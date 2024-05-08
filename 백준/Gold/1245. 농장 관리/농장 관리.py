import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())

direction = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

farm = []
for _ in range(n):
    farm.append(list(map(int, sys.stdin.readline().split())))

high = [[0] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]
def check(r, c, num):
    if r < 0 or r >= n or c < 0 or c >= m: return True
    if farm[r][c] > num: return False
    if farm[r][c] < num:
        high[r][c] = -1
        return True
    if high[r][c] != 0: return True if high[r][c] > 0 else False
    if visited[r][c]: return True
    
    visited[r][c] = True
    
    result = True
    for dr, dc in direction:
        result &= check(r + dr, c + dc, num)
    
    high[r][c] = 1 if result else -1
    
    return result
    

answer = 0
for r in range(n):
    for c in range(m):
        if high[r][c] != 0: continue
        
        if check(r, c, farm[r][c]):
            answer += 1

print(answer)