import sys

n, m = map(int, sys.stdin.readline().split())

nums = list(range(1, n + 1))
elements = list(map(int, sys.stdin.readline().split()))
now = 0
answer = 0

for e in elements:
    next = nums.index(e)
    
    if now <= next:
        answer += min(next - now, now + len(nums) - next)
    else:
        answer += min(now - next, next + len(nums) - now)
    
    del nums[next]
    now = next if next < len(nums) else 0

print(answer)