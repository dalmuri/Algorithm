import sys

n, m, k = map(int, sys.stdin.readline().split())

if (n&1):
    n -= 1
    k -= 1

if n > m * 2:
    k -= n - m * 2
    n = m * 2
elif n < m * 2:
    k -= m - n // 2
    m = n // 2

if k > 0:
    cnt = k // 3 + min(k % 3, 1)
    n -= 2 * cnt
    m -= cnt

print(m)