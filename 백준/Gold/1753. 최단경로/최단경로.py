import sys
from heapq import heappush, heappop

inf = 987654321
v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

edges = [[] for _ in range(v + 1)]
for _ in range(e):
    start, end, weight = map(int, sys.stdin.readline().split())
    edges[start].append([end, weight])

hq = []
heappush(hq, [0, k])
dist = [inf] * (v + 1)
dist[k] = 0

while hq:
    now_d, now = heappop(hq)
    
    if now_d > dist[now]: continue
    
    for next, next_d in edges[now]:
        next_d += dist[now]
        
        if next_d < dist[next]:
            dist[next] = next_d
            heappush(hq, [next_d, next])

for i in range(1, v + 1):
    print(dist[i] if dist[i] < inf else "INF")