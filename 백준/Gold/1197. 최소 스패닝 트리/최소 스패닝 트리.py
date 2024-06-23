import sys
from heapq import heappush, heappop

v, e = map(int, sys.stdin.readline().split())

edges = [[] for _ in range(v + 1)]
for _ in range(e):
    a, b, w = map(int, sys.stdin.readline().split())
    edges[a].append([b, w])
    edges[b].append([a, w])

answer = 0
visited = [False] * (v + 1)
hq = []
heappush(hq, [0, 1, 1]) # weight, v1, v2
while hq:
    weight, v1, v2 = heappop(hq)
    if visited[v2]: continue
    
    visited[v2] = True
    answer += weight
    for node, w in edges[v2]:
        if visited[node]: continue
        heappush(hq, [w, v2, node])

print(answer)