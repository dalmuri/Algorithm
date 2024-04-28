import sys

n, m = map(int, sys.stdin.readline().split())

nums = [0] * n
for i in range(n):
    nums[i] = int(sys.stdin.readline())

for card in range(2, m + 1):
    for i in range(len(nums) - 1):
        if nums[i] % card > nums[i + 1] % card:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]

for num in nums:
    print(num)