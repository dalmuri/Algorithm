import sys

n = int(sys.stdin.readline())

triangle = []
for _ in range(n):
    triangle.append(list(map(int, sys.stdin.readline().split())))

for i in reversed(range(n - 1)):
    for j in range(i + 1):
        triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1])

print(triangle[0][0])