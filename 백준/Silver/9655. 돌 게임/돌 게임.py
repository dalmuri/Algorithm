import sys

n = int(sys.stdin.readline())
print("SK" if (n & 1) else "CY")