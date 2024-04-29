import sys

n = int(sys.stdin.readline())

sell = [] # sell[i][j] = i가 j에게 판매한 가격
for _ in range(n):
    sell.append(list(map(int, list(sys.stdin.readline().strip()))))

dp = [[[-1] * (1<<n) for j in range(n)] for i in range(10)] # dp[price][owner][route]

def calc(price, owner, route):
    if dp[price][owner][route] != -1: return dp[price][owner][route]
    
    result = 0
    for i in range(n):
        if ((1<<i)&route) != 0 or sell[owner][i] < price: continue
        
        result = max(result, calc(sell[owner][i], i, route | (1 << i)))
    
    result += 1
    dp[price][owner][route] = result
    return result

print(calc(0, 0, 1))