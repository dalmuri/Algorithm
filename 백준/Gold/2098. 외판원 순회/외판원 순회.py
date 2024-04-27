import sys

n = int(sys.stdin.readline())
inf = 16_000_001
cost = []
for _ in range(n):
    cost.append(list(map(int, sys.stdin.readline().split())))

info = [[-1] * (1<<n) for _ in range(n)] # info[i][mask] = mask 경로를 따라 i에 왔을 때, 그 이후 비용의 최솟값

def search(city, route):
    if route == (1 << n) - 1: return cost[city][0] if cost[city][0] > 0 else inf
    if info[city][route] != -1 : return info[city][route] # 이미 탐색함
    
    result = inf
    for i in range(n):
        if (1 << i) & route != 0 or cost[city][i] == 0: continue
        
        result = min(result, search(i, route | (1 << i)) + cost[city][i])
    
    info[city][route] = result
    return result

print(search(0, 1))