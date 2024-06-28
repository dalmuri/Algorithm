import sys

n, m = map(int, sys.stdin.readline().split())
roads = []
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    roads.append([c, a, b])

roads.sort()
root = list(range(n + 1))


def get_root(home):
    if root[home] == home:
        return home
    root[home] = get_root(root[home])
    return root[home]


def union(a, b):
    root_a = get_root(a)
    root_b = get_root(b)
    root[max(root_a, root_b)] = min(root_a, root_b)


sum_cost = 0
max_cost = 0
cnt = 0
for cost, a, b in roads:
    if get_root(a) == get_root(b): continue
    
    sum_cost += cost
    max_cost = max(max_cost, cost)
    cnt += 1
    
    union(a, b)
    if cnt == n: break

print(sum_cost - max_cost)