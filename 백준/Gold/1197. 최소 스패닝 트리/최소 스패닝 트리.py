import sys
from heapq import heappush, heappop

v, e = map(int, sys.stdin.readline().split())

edges = []
for _ in range(e):
    a, b, w = map(int, sys.stdin.readline().split())
    heappush(edges, [w, a, b])

answer = 0
root = list(range(v + 1))


def get_root(node):
    if root[node] == node:
        return node
    root[node] = get_root(root[node])
    return root[node]


while edges:
    weight, v1, v2 = heappop(edges)
    r1 = get_root(v1)
    r2 = get_root(v2)
    if r1 == r2: continue
    
    answer += weight
    root[max(r1, r2)] = min(r1, r2)

print(answer)