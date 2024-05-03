import sys
sys.setrecursionlimit(10**5)

def solution(n, lighthouse):
    road = [[] for _ in range(n + 1)]
    for a, b in lighthouse:
        road[a].append(b)
        road[b].append(a)
    
    lighted = [False] * (n + 1)
    
    def turn_on(node, parent):
        result = 0
        for child in road[node]:
            if child == parent: continue
            
            result += turn_on(child, node)
            
            if not lighted[child] and not lighted[node]:
                lighted[node] = True
                result += 1
        
        return result
    
    return turn_on(1, -1)