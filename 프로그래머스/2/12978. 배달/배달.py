import math
import heapq

def calc_distance(N, costs):
    dist = [math.inf for i in range(N + 1)]
    dist[1] = 0
    hq = []
    heapq.heappush(hq, [0, 1]) # distance, idx
    while hq:
        now = heapq.heappop(hq)
        now_idx = now[1]
        now_dist = now[0]
        
        if dist[now_idx] < now_dist:
            continue
        for c in costs[now_idx]:
            next_idx = c[0]
            next_dist = dist[now_idx] + c[1]
            if next_dist < dist[next_idx]:
                dist[next_idx] = next_dist
                heapq.heappush(hq, [next_dist, next_idx])
    return dist
    

def solution(N, road, K):
    costs = [[] for i in range(N + 1)]
    for r in road:
        costs[r[0]].append([r[1], r[2]])
        costs[r[1]].append([r[0], r[2]])
    
    dist = calc_distance(N, costs)
    
    answer = 0
    for i in range(1, N + 1):
        if dist[i] <= K:
            answer += 1

    return answer