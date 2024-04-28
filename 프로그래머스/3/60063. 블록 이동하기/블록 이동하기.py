import sys
from collections import deque
sys.setrecursionlimit(10**7)

direction = [[1, 0], [0, 1]] # 하 우
inf = 10**7

q = deque()

def turn(r1, c1, d, n, board):
    result = []
    if d == 0: # 상하 방향
        r2 = r1 + 1
        if c1 - 1 >= 0 and board[r2][c1 - 1] == 0: result.append([r1, c1 - 1, 1]) # 축[r1, c1], 시계방향
        if c1 + 1 < n and board[r2][c1 + 1] == 0: result.append([r1, c1, 1]) # 축[r1, c1], 반시계방향
        if c1 - 1 >= 0 and board[r1][c1 - 1] == 0: result.append([r2, c1 - 1, 1]) # 축[r2, c2], 반시계방향
        if c1 + 1 < n and board[r1][c1 + 1] == 0: result.append([r2, c1, 1]) # 축[r2, c2], 시계방향
    else: # 좌우 방향
        c2 = c1 + 1
        if r1 - 1 >= 0 and board[r1 - 1][c2] == 0: result.append([r1 - 1, c1, 0]) # 축[r1, c1], 반시계방향
        if r1 + 1 < n and board[r1 + 1][c2] == 0: result.append([r1, c1, 0]) # 축[r1, c1], 시계방향
        if r1 - 1 >= 0 and board[r1 - 1][c1] == 0: result.append([r1 - 1, c2, 0]) # 축[r2, c2], 시계방향
        if r1 + 1 < n and board[r1 + 1][c1] == 0: result.append([r1, c2, 0]) # 축[r2, c2], 반시계방향
    
    return result

def search(n, dist, board):
    r1, c1, d, res = q.popleft()
    r2 = r1 + direction[d][0]
    c2 = c1 + direction[d][1]
    if r1 < 0 or r1 >= n or c1 < 0 or c1 >= n: return
    if r2 < 0 or r2 >= n or c2 < 0 or c2 >= n: return
    if board[r1][c1] == 1 or board[r2][c2] == 1: return
    if 0 <= dist[r1][c1][d] <= res: return
    
    dist[r1][c1][d] = res
    
    for dd in direction:
        q.append([r1 + dd[0], c1 + dd[1], d, res + 1])
        q.append([r1 - dd[0], c1 - dd[1], d, res + 1])
    
    to_search = turn(r1, c1, d, n, board)
    for nxt in to_search:
        q.append([nxt[0], nxt[1], nxt[2], res + 1])
    

def solution(board):
    n = len(board)
    dist = [[[-1] * 2 for j in range(n)] for i in range(n)]
    q.append([n - 2, n - 1, 0, 0])
    q.append([n - 1, n - 2, 1, 0])
    while q:
        search(n, dist, board)
        if dist[0][0][1] != -1:
            break
    
    return dist[0][0][1]