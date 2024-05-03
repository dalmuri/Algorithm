import sys

n, m = map(int, sys.stdin.readline().split())
print(m // 2 * n + m % 2 * n // 2)