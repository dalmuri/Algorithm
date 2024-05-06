import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
city = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

homes = []
chickens = []
for r in range(n):
    for c in range(n):
        if city[r][c] == 1:
            homes.append((r, c))
        elif city[r][c] == 2:
            chickens.append((r, c))

dists = [[0] * len(homes) for _ in range(len(chickens))]
for c, chicken in enumerate(chickens):
    for h, home in enumerate(homes):
        dists[c][h] = abs(chicken[0] - home[0]) + abs(chicken[1] - home[1])

answer = 1301
for com in combinations(range(len(chickens)), m):
    answer = min(answer, sum(min(dists[c][h] for c in com) for h in range(len(homes))))

print(answer)