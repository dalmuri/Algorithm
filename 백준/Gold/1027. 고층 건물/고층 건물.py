import sys

n = int(sys.stdin.readline())
buildings = list(map(int, sys.stdin.readline().split()))

answer = 0
for x1, y1 in enumerate(buildings):
    cnt = 0
    prev_gradient = -1_000_000_001
    for x2 in reversed(range(0, x1)):
        y2 = buildings[x2]
        gradient = (y2 - y1) / (x1 - x2)
        if prev_gradient < gradient:
            cnt += 1
        prev_gradient = max(prev_gradient, gradient)
    
    prev_gradient = -1_000_000_001
    for x2 in range(x1 + 1, n):
        y2 = buildings[x2]
        gradient = (y2 - y1) / (x2 - x1)
        if prev_gradient < gradient:
            cnt += 1
        prev_gradient = max(prev_gradient, gradient)
    
    answer = max(answer, cnt)

print(answer)