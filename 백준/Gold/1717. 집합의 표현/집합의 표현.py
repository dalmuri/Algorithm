import sys
sys.setrecursionlimit(10**7)

n, m = map(int, sys.stdin.readline().split())
parent = list(range(n + 1))

def get_root(num):
    if parent[num] == num:
        return num
    parent[num] = get_root(parent[num])
    return parent[num]


for _ in range(m):
    cmd, a, b = map(int, sys.stdin.readline().split())
    if cmd == 0:
        if a == b: continue
        root_a = get_root(a)
        root_b = get_root(b)
        parent[max(root_a, root_b)] = min(root_a, root_b)
    else:
        if get_root(a) == get_root(b):
            print("YES")
        else:
            print("NO")