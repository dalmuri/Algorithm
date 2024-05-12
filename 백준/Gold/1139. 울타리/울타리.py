import sys
from math import sqrt
from itertools import combinations

n = int(sys.stdin.readline())
fence = list(map(int, sys.stdin.readline().split()))
fence.sort()

dp = [-1] * (1 << n)

def get_area(a, b, c):
    p = (a + b + c) / 2
    return sqrt(p * (p - a) * (p - b) * (p - c))


def calc(bitmask):
    if dp[bitmask] != -1: return dp[bitmask]
    
    result = 0
    for i, j, k in combinations(range(n), 3):
        if (bitmask & (1 << i)) or (bitmask & (1 << j)) or (bitmask & (1 << k)): continue # 하나라도 사용한 상태이면 스킵
        if fence[i] + fence[j] > fence[k]:
            result = max(result, get_area(fence[i], fence[j], fence[k]) + calc(bitmask | (1 << i) | (1 << j) | (1 << k)))
    
    dp[bitmask] = result
    return result


print(calc(0))