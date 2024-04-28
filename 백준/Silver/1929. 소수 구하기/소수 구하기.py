import sys

m, n = map(int, sys.stdin.readline().split())

is_prime = [True] * (n + 1)
is_prime[1] = False

for num in range(2, n + 1):
    if not is_prime[num]: continue
    
    for i in range(num * 2, n + 1, num):
        is_prime[i] = False

for num in range(m, n + 1):
    if is_prime[num]:
        print(num)