import sys

def get_taxi_dist(r1, c1, r2, c2):
    return abs(r1 - r2) + abs(c1 - c2)


n, m = map(int, sys.stdin.readline().split())
d = int(sys.stdin.readline())

answer = 0
for r in range(n):
    for c in range(m):
        if get_taxi_dist(r, c, 0, 0) >= d: continue
        if get_taxi_dist(r, c, 0, m - 1) >= d: continue
        if get_taxi_dist(r, c, n - 1, 0) >= d: continue
        if get_taxi_dist(r, c, n - 1, m - 1) >= d: continue
        
        answer += 1

print(answer)