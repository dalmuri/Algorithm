import sys

def is_in_circle(x, y, cx, cy, r):
    return (cx - x)**2 + (cy - y)**2 < r**2


t = int(sys.stdin.readline())

for _ in range(t):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    
    answer = 0
    for i in range(n):
        cx, cy, r = map(int, sys.stdin.readline().split())
        
        if is_in_circle(x1, y1, cx, cy, r) ^ is_in_circle(x2, y2, cx, cy, r):
            answer += 1
    
    print(answer)