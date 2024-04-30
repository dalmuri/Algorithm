import sys

l = int(sys.stdin.readline())
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())
d = int(sys.stdin.readline())

print(l - max(a // c + min(a % c, 1), b // d + min(b % d, 1)))