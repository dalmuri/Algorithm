import sys
from collections import deque

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상 우 하 좌

m, n = map(int, sys.stdin.readline().split())

tomato = []
inf = 10**6 + 1
days = [[inf] * m for _ in range(n)]
q = deque()
answer = -1

for _ in range(n):
    tomato.append(list(map(int, sys.stdin.readline().split())))

for r in range(n):
    for c in range(m):
        if tomato[r][c] == 1:
            q.append([0, r, c])

while q:
    day, r, c = q.popleft()
    if days[r][c] <= day: continue
    
    days[r][c] = day
    for dr, dc in direction:
        next_r = r + dr
        next_c = c + dc
        if 0 <= next_r < n and 0 <= next_c < m and tomato[next_r][next_c] == 0:
            q.append([day + 1, next_r, next_c])

for r in range(n):
    for c in range(m):
        if tomato[r][c] != -1:
            answer = max(answer, days[r][c])

print(answer if answer < inf else -1)