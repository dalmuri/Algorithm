import sys
from math import sqrt

a, b = map(int, sys.stdin.readline().split())
ra = int(sqrt(a))
rb = int(sqrt(b))

answer = 0
is_prime = [True] * (rb + 1)
is_prime[1] = False

for i in range(2, rb + 1):
    if not is_prime[i]: continue
    
    exp = i**2
    while exp <= b:
        if a <= exp:
            answer += 1
        exp *= i
    
    for j in range(i**2, rb + 1, i):
        is_prime[j] = False

print(answer)