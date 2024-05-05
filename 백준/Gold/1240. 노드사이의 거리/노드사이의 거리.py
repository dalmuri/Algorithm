import sys

sys.setrecursionlimit(10**7)

inf = 10_000_001
n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, d = map(int, sys.stdin.readline().split())
    graph[a].append([b, d])
    graph[b].append([a, d])

dist = [[inf] * (n + 1) for _ in range(n + 1)]
parents = [-1] * (n + 1)

def make_tree(node, parent):
    children = []
    dist[node][node] = 0
    for child, d in graph[node]:
        dist[node][child] = d
        if child == parent: continue
        parents[child] = node
        children.append(child)
        
        subchildren = make_tree(child, node)
        for subchild in subchildren:
            dist[node][subchild] = d + dist[child][subchild]
        children += subchildren
    return children


def get_dist(a, b):
    if dist[a][b] < inf: return dist[a][b]
    return dist[a][parents[a]] + get_dist(parents[a], b)


make_tree(1, -1)
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    print(get_dist(a, b))