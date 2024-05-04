import sys

inf = 101
n, m = map(int, sys.stdin.readline().split())

dist = [[inf] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    dist[a][b] = 1
    dist[b][a] = 1

# Floyd Warshall
for mid in range(1, n + 1):
    dist[mid][mid] = 0
    for start in range(1, n + 1):
        for end in range(1, n + 1):
            dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end])

min_bacon = sum(dist[1][1:])
answer = 1
for i in range(2, n + 1):
    bacon = sum(dist[i][1:])
    if bacon < min_bacon:
        min_bacon = bacon
        answer = i

print(answer)