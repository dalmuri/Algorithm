import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

inc = [1] * n
for i in range(1, n):
    for j in range(i):
        if a[j] < a[i]:
            inc[i] = max(inc[i], inc[j] + 1)

dec = [1] * n
for i in reversed(range(n - 1)):
    for j in reversed(range(i, n)):
        if a[i] > a[j]:
            dec[i] = max(dec[i], dec[j] + 1)

print(max(inc[i] + dec[i] - 1 for i in range(n)))