import sys
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())

words = [set() for _ in range(n)]
used = set()
for i in range(n):
    w = sys.stdin.readline().strip()
    for c in w:
        words[i].add(c)
        used.add(c)
    words[i] -= set(['a', 'c', 'i', 'n', 't'])

answer = 0
if k >= 5:
    used -= set(['a', 'c', 'i', 'n', 't'])
    for comb in combinations(used, min(k - 5, len(used))):
        dictionary = set(comb)
        cnt = 0
        
        for word in words:
            if not len(word - dictionary):
                cnt += 1
        
        answer = max(answer, cnt)

print(answer)