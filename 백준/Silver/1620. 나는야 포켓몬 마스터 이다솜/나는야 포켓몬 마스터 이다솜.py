import sys

n, m = map(int, sys.stdin.readline().split())
pokemon = dict()
pokedex = [""]

for i in range(1, n + 1):
    mon = sys.stdin.readline().strip()
    pokemon[mon] = i
    pokedex.append(mon)

for _ in range(m):
    q = sys.stdin.readline().strip()
    if q.isdigit():
        print(pokedex[int(q)])
    else:
        print(pokemon[q])