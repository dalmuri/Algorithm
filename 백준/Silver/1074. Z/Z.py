n, r, c = map(int, input().split(" "))

answer = 0
while n >= 0:
    if 2**(n - 1) <= r:
        answer += 2**(2*n - 1)
        r -= 2**(n - 1)
    
    if 2**(n - 1) <= c:
        answer += 2**(2*n - 2)
        c -= 2**(n - 1)
    
    n -= 1

print(answer)