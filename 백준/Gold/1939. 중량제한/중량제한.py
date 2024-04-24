import sys

def can_visit(weight, source, destination, n, bridges):
    visited = [False] * (n + 1)
    to_visit = [source] # stack
    while to_visit:
        now = to_visit.pop()
        visited[now] = True
        
        for next, limit in bridges[now]:
            if weight <= limit and not visited[next]:
                to_visit.append(next)
                if next == destination:
                    return True
    
    return False
        

n, m = map(int, sys.stdin.readline().split())

bridges = [[] for _ in range(n + 1)]
max_weight = 0

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    bridges[a].append((b, c))
    bridges[b].append((a, c))
    max_weight = max(max_weight, c)

source, destination = map(int, sys.stdin.readline().split())

# 이진탐색
start = 1
end = max_weight
answer = 0
while start <= end:
    mid = (start + end) // 2
    able = can_visit(mid, source, destination, n, bridges)
    
    if able: # 도착 성공
        answer = mid
        start = mid + 1
    else:
        end = mid - 1

print(answer)