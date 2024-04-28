import sys
sys.setrecursionlimit(10**5)
inf = 10000
n = 102

plane = [[0] * n for _ in range(n)] # 0: 없음 1: 테두리 2: 사각형 내부
dist = [[inf] * n for _ in range(n)]
direction = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상 우 하 좌

def search(x, y, length, dest_x, dest_y):
    if x < 0 or x >= n or y < 0 or y >= n: return
    if plane[x][y] != 1: return
    if dist[x][y] <= length: return
    
    dist[x][y] = length
    if x == dest_x and y == dest_y: return
    
    for d in direction:
        search(x + d[0], y + d[1], length + 1, dest_x, dest_y)

def solution(rectangle, characterX, characterY, itemX, itemY):
    for rec in rectangle:
        for x in range(rec[0] * 2, rec[2] * 2 + 1):
            for y in range(rec[1] * 2, rec[3] * 2 + 1):
                if plane[x][y] == 2: continue
                
                if x == rec[0] * 2 or x == rec[2] * 2 or y == rec[1] * 2 or y == rec[3] * 2:
                    plane[x][y] = 1
                else:
                    plane[x][y] = 2
    
    search(characterX * 2, characterY * 2, 0, itemX * 2, itemY * 2)
    
    return dist[itemX * 2][itemY * 2] // 2