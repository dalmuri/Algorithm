import sys

x = int(sys.stdin.readline())
n = int(sys.stdin.readline())

price = 0
for _ in range(n):
    item, cost = map(int, sys.stdin.readline().split())
    price += item * cost

if price == x:
    print("Yes")
else:
    print("No")