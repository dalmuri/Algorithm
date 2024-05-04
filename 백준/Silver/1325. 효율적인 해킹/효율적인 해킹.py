import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())

coms = [[] for _ in range(n + 1)] # coms[i] = i를 믿는 컴퓨터들
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    coms[b].append(a)

cnts = [0] * (n + 1)

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    visited[i] = True
    q = deque([i])
    while q:
        com = q.popleft()
        cnts[i] += 1
        for c in coms[com]:
            if not visited[c]:
                visited[c] = True
                q.append(c)

    
max_cnt = max(cnts)
answer = []
for i in range(1, n + 1):
    if cnts[i] == max_cnt:
        answer.append(i)

print(*answer)