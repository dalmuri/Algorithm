import sys

n = int(sys.stdin.readline())
col = [-1] * n

def able(idx):
    for i, r in enumerate(col[:idx]):
        if r == col[idx] or r + (idx - i) == col[idx] or r - (idx - i) == col[idx]:
            return False
    return True


def cnt(idx):
    if idx >= n:
        return 1
    
    result = 0
    for row in range(n):
        col[idx] = row
        
        if able(idx):
            result += cnt(idx + 1)
    
    return result


print(cnt(0))