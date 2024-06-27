import sys
from heapq import heappush, heappop

inf = 987654321
n, e = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(n + 1)]
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    edges[a].append([b, c])
    edges[b].append([a, c])

v1, v2 = map(int, sys.stdin.readline().split())

def dijkstra(start):
    dist = [inf] * (n + 1)
    dist[start] = 0
    
    hq = []
    heappush(hq, [0, start])
    
    while hq:
        now_d = hq[0][0]
        now = hq[0][1]
        heappop(hq)
        
        if now_d > dist[now]: continue
        
        for edge in edges[now]:
            next = edge[0]
            next_d = now_d + edge[1]
            
            if next_d < dist[next]:
                dist[next] = next_d
                heappush(hq, [next_d, next])
    
    return dist


dist_v1 = dijkstra(v1)
dist_v2 = dijkstra(v2)

answer = min(dist_v1[1] + dist_v1[v2] + dist_v2[n], dist_v2[1] + dist_v2[v1] + dist_v1[n])
if answer >= inf:
    answer = -1

print(answer)