import sys

n = int(sys.stdin.readline())

for i in range(5):
    for j in range(n):
        print("@" * n * 5 if i & 1 else "@" * n + " " * n * 3 + "@" * n)