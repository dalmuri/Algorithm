import sys

x = int(sys.stdin.readline())
y = int(sys.stdin.readline())
print((1 if y > 0 else 4) if x > 0 else (2 if y > 0 else 3))