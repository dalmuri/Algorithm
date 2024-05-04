import sys
a, b, v = map(int, sys.stdin.readline().split())
print((v - a) // (a - b) + min((v - a) % (a - b), 1) + 1)