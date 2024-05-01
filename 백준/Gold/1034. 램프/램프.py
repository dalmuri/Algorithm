import sys
from copy import deepcopy

def turn(col, lamp):
    for r in range(n):
        lamp[r][col] = (lamp[r][col] + 1) % 2

n, m = map(int, sys.stdin.readline().split())
lamp = []
cnt = 0
for _ in range(n):
    lamp.append(list(map(int, list(sys.stdin.readline().strip()))))

k = int(sys.stdin.readline())


answer = 0
for r in range(n):
    zero = 0
    columns = []
    for c in range(m):
        if lamp[r][c] == 0:
            zero +=1
            columns.append(c)
    
    if zero > k or ((k - zero)&1):
        continue
    
    tmp = deepcopy(lamp)
    for col in columns:
        turn(col, tmp)
    
    cnt = 0
    for r in range(n):
        if all(l == 1 for l in tmp[r]):
            cnt += 1
    
    answer = max(answer, cnt)

print(answer)