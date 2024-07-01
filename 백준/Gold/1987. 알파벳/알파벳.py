import sys

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]
r, c = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().strip()) for _ in range(r)]

visited = [False] * 26

def check(row, col):
    if row < 0 or row >= r or col < 0 or col >= c: return 0
    ch = ord(board[row][col]) - ord('A')
    if visited[ch]: return 0
    
    tmp = visited[ch]
    visited[ch] = True
    result = 1
    for dr, dc in direction:
        result = max(result, check(row + dr, col + dc) + 1)
        
    visited[ch] = tmp
    return result


print(check(0, 0))