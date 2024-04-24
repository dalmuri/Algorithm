import sys

def can_visit(weight, start, end, n, bridge):
    visited = [False] * (n + 1)
    stk = [start]
    while stk:
        now = stk.pop()
        visited[now] = True
        
        for next, limit in bridge[now]:
            if weight <= limit and not visited[next]:
                stk.append(next)
                if next == end:
                    return True
    
    return False
        

n, m = map(int, sys.stdin.readline().split())

bridge = [[] for _ in range(n + 1)]
max_weight = 1_000_000_000

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    bridge[a].append((b, c))
    bridge[b].append((a, c))
    max_weight = max(max_weight, c)

start, end = map(int, sys.stdin.readline().split())

# 중량 계산
left = 1
right = max_weight
answer = 0
while left <= right:
    mid = (left + right) // 2
    able = can_visit(mid, start, end, n, bridge)
    
    if able: # 도착 성공
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer)