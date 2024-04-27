import sys

n, m = map(int, sys.stdin.readline().split())

basket = list(range(1, n + 1))

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    left, right = i - 1, j - 1
    while left < right:
        basket[left], basket[right] = basket[right], basket[left]
        left += 1
        right -= 1

print(*basket)