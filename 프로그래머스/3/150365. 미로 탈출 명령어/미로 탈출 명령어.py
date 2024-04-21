def solution(n, m, x, y, r, c, k):
    down = 0
    left = 0
    right = 0
    up = 0
    
    if r - x > 0: down = r - x
    else: up = x - r
    
    if c - y > 0: right = c - y
    else: left = y - c
    
    k -= down + left + right + up
    if k < 0 or (k & 1) == 1: return "impossible"
    
    down_over = min(n - max(r, x), k // 2)
    k -= down_over * 2
    left_over = min(min(c, y) - 1, k // 2)
    k -= left_over * 2
    
    return "d"*(down + down_over) + "l"*(left + left_over) + "rl"*(k // 2) + "r"*(right + left_over) + "u"*(up + down_over)