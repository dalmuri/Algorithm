import sys
import math
from itertools import combinations

n = int(sys.stdin.readline())

digits = [0]
digit = 0
for i in range(1, 11):
    digits.append(digits[i - 1] + math.comb(10, i))
    if n <= digits[i]:
        digit = i
        break

if n > digits[-1]:
    answer = -1
else:
    nums = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    c = list(combinations(nums, digit))
    c.reverse()
    num = c[n - digits[digit - 1] - 1]
    answer = ""
    for i in num:
        answer += str(i)

print(answer)