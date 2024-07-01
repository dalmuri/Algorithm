import sys

n, m = map(int, sys.stdin.readline().split())
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

tetrominos = [[[1, 1, 1, 1]], [[1], [1], [1], [1]],
              [[1, 1], [1, 1]],
              [[0, 1, 0], [1, 1, 1]], [[1, 0], [1, 1], [1, 0]], [[1, 1, 1], [0, 1, 0]], [[0, 1], [1, 1], [0, 1]],
              [[1, 0], [1, 1], [0, 1]], [[0, 1, 1], [1, 1, 0]],
              [[0, 1], [1, 1], [1, 0]], [[1, 1, 0], [0, 1, 1]],
              [[1, 0], [1, 0], [1, 1]], [[1, 1, 1], [1, 0, 0]], [[1, 1], [0, 1], [0, 1]], [[0, 0, 1], [1, 1, 1]],
              [[0, 1], [0, 1], [1, 1]], [[1, 0, 0], [1, 1, 1]], [[1, 1], [1, 0], [1, 0]], [[1, 1, 1], [0, 0, 1]]]


def calc(r, c, tetromino):
    result = 0
    for dr in range(len(tetromino)):
        for dc in range(len(tetromino[dr])):
            if tetromino[dr][dc] == 0: continue
            
            row = r + dr
            col = c + dc
            if row < 0 or row >= n or col < 0 or col >= m: return 0
            
            result += paper[row][col]
    
    return result
            

answer = 0
for r in range(n):
    for c in range(m):
        for tetromino in tetrominos:
            answer = max(answer, calc(r, c, tetromino))

print(answer)