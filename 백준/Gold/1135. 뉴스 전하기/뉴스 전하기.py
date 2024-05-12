import sys

inf = 10**4
n = int(sys.stdin.readline())
superiors = list(map(int, sys.stdin.readline().split()))

delay = [[] for _ in range(n)]
for i in reversed(range(n)):
    if not delay[i]:
        delay[superiors[i]].append(0)
        continue
    
    delay[i].sort(reverse=True)
    delay[superiors[i]].append(max(a + b for a, b in zip(delay[i], range(1, len(delay[i]) + 1))))

print(delay[-1][0])