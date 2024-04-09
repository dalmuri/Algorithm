import heapq

def search(start, n, types, costs, answer):
    # Dijkstra
    intensities = [10_000_001] * (n + 1)
    intensities[start] = 0
    hq = [(0, start)] # (intensity, idx)
    
    while hq:
        now_intensity, now_idx = heapq.heappop(hq)
        
        # intensity가 가장 낮은 산봉우리에 도달하면 answer 확인 후 return
        if types[now_idx] == 2:
            if now_intensity < answer[1] or (now_intensity == answer[1] and now_idx < answer[0]):
                answer[0] = now_idx
                answer[1] = now_intensity
            return
        
        if now_intensity > intensities[now_idx]:
            continue
        for cost in costs[now_idx]:
            next_idx = cost[0]
            next_intensity = max(now_intensity, cost[1])
            
            # 출입구인 경우 계산하지 않음
            if types[next_idx] == 1:
                continue
            
            if next_intensity < intensities[next_idx]:
                intensities[next_idx] = next_intensity
                heapq.heappush(hq, (next_intensity, next_idx))

def solution(n, paths, gates, summits):
    answer = [-1, 10_000_001]
    
    types = [0] * (n + 1) # 0: 쉼터, 1: 출입구, 2: 산봉우리
    for gate in gates:
        types[gate] = 1
    for summit in summits:
        types[summit] = 2
    
    # 모든 cost 설정
    costs = [[] for i in range(n + 1)]
    for path in paths:
        costs[path[0]].append([path[1], path[2]])
        costs[path[1]].append([path[0], path[2]])
    
    # 각 gate에서 출발하여 확인
    for gate in gates:
        search(gate, n, types, costs, answer)
    
    return answer