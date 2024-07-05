import sys

direction = [[0, 1], [1, 0], [0, -1], [-1, 0]] # 상 우 하 좌

n, t = map(int, sys.stdin.readline().split())
d = 1
prev = 0
x = 0
y = 0
for i in range(n):
    ti, turn = sys.stdin.readline().strip().split(" ")
    ti = int(ti)
    
    x += direction[d][0] * (ti - prev)
    y += direction[d][1] * (ti - prev)
    
    if turn == "left":
        d = (d + 4 - 1) % 4
    else:
        d = (d + 1) % 4
    prev = ti

x += direction[d][0] * (t - prev)
y += direction[d][1] * (t - prev)

print(x, y, sep=" ")