import sys

a, b, c = map(int, sys.stdin.readline().split())

to_multiply = 1
a %= c
while b > 1:
    if (b&1):
        to_multiply = to_multiply * a % c
    a = a * a % c
    b //= 2

print(a * to_multiply % c)