import sys

t = int(sys.stdin.readline())
for _ in range(t):
    x, y = map(int, sys.stdin.readline().split())
    
    dist = y - x
    left = 0
    right = 2**31 - 1
    n = right
    while left <= right:
        mid = (left + right) // 2
        
        if dist <= mid * mid + mid:
            n = mid
            right = mid - 1
        else:
            left = mid + 1
    
    print(2 * n if dist > n * n else 2 * n - 1)