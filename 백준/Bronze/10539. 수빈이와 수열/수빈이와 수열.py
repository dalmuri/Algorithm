import sys

n = int(sys.stdin.readline())
b = list(map(int, sys.stdin.readline().split()))

for i in range(len(b)):
    b[i] *= (i + 1)

for i in reversed(range(1, len(b))):
    b[i] -= b[i - 1]

print(*b)