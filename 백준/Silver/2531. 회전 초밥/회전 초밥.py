import sys

n, d, k, c = map(int, sys.stdin.readline().split())
sushi = [0] * n
for i in range(n):
    sushi[i] = int(sys.stdin.readline())
d = len(set(sushi)) if c in sushi else len(set(sushi)) + 1
sushi += sushi[:k - 1]

answer = 0
for i in range(len(sushi) - k + 1):
    kinds = set(sushi[i:i+k])
    answer = max(answer, len(kinds) if c in kinds else len(kinds) + 1)
    
    if answer == d:
        break

print(answer)