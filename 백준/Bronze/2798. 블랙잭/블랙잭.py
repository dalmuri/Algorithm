import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

answer = 0
for a, b, c in combinations(nums, 3):
    if answer < a + b + c <= m:
        answer = a + b + c

print(answer)