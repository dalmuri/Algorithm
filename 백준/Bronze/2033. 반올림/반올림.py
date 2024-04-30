import sys

n = list(map(int, list(sys.stdin.readline().strip())))

for i in reversed(range(len(n))):
    if i > 0 and n[i] >= 5:
        n[i - 1] += 1

print(str(n[0]) + "0" * (len(n) - 1))