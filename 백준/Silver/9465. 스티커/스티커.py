import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    stickers = []
    for i in range(2):
        stickers.append(list(map(int, sys.stdin.readline().split())))
    
    if n == 1:
        print(max(stickers[0][0], stickers[1][0]))
        continue
    
    point = [[0] * n, [0] * n]
    point[0][0] = stickers[0][0]
    point[1][0] = stickers[1][0]
    point[0][1] = stickers[1][0] + stickers[0][1]
    point[1][1] = stickers[0][0] + stickers[1][1]
    
    for i in range(2, n):
        point[0][i] = max(point[1][i - 2], point[1][i - 1]) + stickers[0][i]
        point[1][i] = max(point[0][i - 2], point[0][i - 1]) + stickers[1][i]
    
    print(max(point[0][-1], point[1][-1]))