import sys

n = int(sys.stdin.readline())

answer = [1, 2] * (n // 2)
if (n & 1):
    answer.append(3)

print(*answer, sep=" ")