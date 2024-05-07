def solution(temperature, t1, t2, a, b, onboard):
    inf = 10**6
    target = max(temperature - t2, t1 - temperature)
    cost = [[inf] * (target + 2) for _ in range(len(onboard))]
    # cost[i][j] = i시각에 j온도가 되기 위한 최소 비용
    cost[0][0] = 0
    for i in range(1, len(onboard)):
        start = target if onboard[i] else 0
        end = target + 1
        
        for j in range(start, end + 1):
            # 에어컨 ON, 1도 상승
            if j > 0: cost[i][j] = min(cost[i][j], cost[i - 1][j - 1] + a)
            
            # 온도 유지
            if j == 0: cost[i][j] = min(cost[i][j], cost[i - 1][j]) # 외부 온도와 동일하여 에어컨 OFF
            else: cost[i][j] = min(cost[i][j], cost[i - 1][j] + b) # 외부 온도와 달라 에어컨 ON
            
            # 에어컨 OFF, 1도 하강
            if j < target + 1: cost[i][j] = min(cost[i][j], cost[i - 1][j + 1])
    
    return min(cost[len(onboard) - 1])