import sys
from collections import defaultdict

n, p, q = map(int, sys.stdin.readline().split())
a = defaultdict(int)
a[0] = 1


def get(idx):
    if a[idx] > 0: return a[idx]
    
    a[idx] = get(idx // p) + get(idx // q)
    return a[idx]

print(get(n))