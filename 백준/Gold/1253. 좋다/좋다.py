import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

nums.sort()

answer = 0
for i, target in enumerate(nums):
    left = 0
    right = n - 1
    while left < right:
        if nums[left] + nums[right] < target:
            left += 1
        elif nums[left] + nums[right] > target:
            right -= 1
        else:
            if left == i:
                left += 1
            elif right == i:
                right -= 1
            else:
                answer += 1
                break

print(answer)