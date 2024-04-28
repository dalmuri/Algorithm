import sys

n, s = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

start, end = 0, 0
subtotal = 0 # [start, end) 구간의 합
res = [0, len(nums) + 1]

while end < len(nums):
    if subtotal < s:
        subtotal += nums[end]
        end += 1
    else:
        if end - start < res[1] - res[0]:
            res[0], res[1] = start, end
        
        subtotal -= nums[start]
        start += 1

while start < len(nums) and subtotal >= s:
    if end - start < res[1] - res[0]:
        res[0], res[1] = start, end
        
    subtotal -= nums[start]
    start += 1

print(res[1] - res[0] if res[1] - res[0] <= len(nums) else 0)