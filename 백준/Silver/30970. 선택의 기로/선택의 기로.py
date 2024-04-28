import sys

n = int(sys.stdin.readline())

miniature = []
for _ in range(n):
    miniature.append(list(map(int, sys.stdin.readline().split())))

miniature.sort(key=lambda m: (-m[0], m[1]))
print(miniature[0][0], miniature[0][1], miniature[1][0], miniature[1][1])

miniature.sort(key=lambda m: (m[1], -m[0]))
print(miniature[0][0], miniature[0][1], miniature[1][0], miniature[1][1])