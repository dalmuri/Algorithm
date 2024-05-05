import sys

x, y = map(int, sys.stdin.readline().split())
z = y * 100 // x

left = 1
right = 1_000_000_000
answer = -1
while left <= right:
    mid = (left + right) // 2
    
    if z < (y + mid) * 100 // (x + mid):
        answer = mid
        right = mid - 1
    else:
        left = mid + 1

print(answer)