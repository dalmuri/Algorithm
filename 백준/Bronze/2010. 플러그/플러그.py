import sys

n = int(sys.stdin.readline())
plug = [int(sys.stdin.readline()) for _ in range(n)]

print(sum(plug) - n + 1)