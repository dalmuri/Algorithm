import sys
sys.setrecursionlimit(10**6)

n = int(sys.stdin.readline())

tree = [[] for _ in range(n + 1)]
wolf_sheep = [[0, 0] for _ in range(n + 1)]

for i in range(n - 1):
    t, a, p = sys.stdin.readline().split()
    tree[int(p)].append(i + 2)
    wolf_sheep[i + 2] = [t, int(a)]

def dfs(node, parent):
    result = 0
    for child in tree[node]:
        if child == parent:
            continue
        result += dfs(child, node)
    
    if wolf_sheep[node][0] == 'W':
        result = max(0, result - wolf_sheep[node][1])
    else:
        result += wolf_sheep[node][1]
    
    return result

print(dfs(1, 0))