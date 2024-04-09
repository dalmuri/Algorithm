import math
import heapq

def solution(n, roads, sources, destination):
    rails = [[] for i in range(n + 1)]
    for road in roads:
        rails[road[0]].append(road[1])
        rails[road[1]].append(road[0])
    
    dist = [math.inf for i in range(n + 1)]
    dist[destination] = 0
    hq = []
    heapq.heappush(hq, (0, destination)) #distance, idx
    while hq:
        now = heapq.heappop(hq)
        now_idx = now[1]
        now_dist = now[0]
        
        if now_dist > dist[now_idx]:
            continue
        for rail in rails[now_idx]:
            next_idx = rail
            next_dist = now_dist + 1
            if next_dist < dist[next_idx]:
                dist[next_idx] = next_dist
                heapq.heappush(hq, (next_dist, next_idx))
    
    
    answer = []
    for source in sources:
        if dist[source] == math.inf:
            answer.append(-1)
        else:
            answer.append(dist[source])
    return answer