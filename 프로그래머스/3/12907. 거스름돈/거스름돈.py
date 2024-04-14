def solution(n, money):
    method = [1] + [0] * n
    
    for coin in money:
        for i in range(coin, n + 1):
            method[i] = (method[i] + method[i - coin]) % 1_000_000_007
    
    return method[n]