import math
from itertools import combinations

n = int(input())

digits = [-1]
digit = 0
for i in range(1, 11):
    digits.append(digits[i - 1] + math.comb(10, i))
    if digits[i - 1] < n <= digits[i]:
        digit = i

if n > digits[10]:
    print(-1)
else:
    nums = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    c = list(combinations(nums, digit))
    c.reverse()
    num = c[n - digits[digit - 1] - 1]
    answer = ""
    for i in range(len(num)):
        answer += str(num[i])
    print(answer)