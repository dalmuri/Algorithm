import sys
import itertools

n = int(sys.stdin.readline())
time = list(map(int, sys.stdin.readline().split()))
time.sort()
print(sum(itertools.accumulate(time)))