import sys
sys.setrecursionlimit(10**4)

inf = 3000
direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]
n, m = map(int, sys.stdin.readline().split())

board = []
for _ in range(n):
    board.append(list(sys.stdin.readline().strip()))

visited = [[False] * m for _ in range(n)]
dp = [[0] * m for _ in range(n)]

def search(r, c):
    if r < 0 or r >= n or c < 0 or c >= m: return 0
    if dp[r][c] > 0: return dp[r][c]
    if board[r][c] == 'H': return 0
    if visited[r][c]: return inf
    
    visited[r][c] = True
    
    result = 0
    for dr, dc in direction:
        result = max(result, search(r + dr * int(board[r][c]), c + dc * int(board[r][c])))
    
    result = min(result + 1, inf)
    dp[r][c] = result
    
    visited[r][c] = False
    
    return result

answer = search(0, 0)
if answer == inf: answer = -1
print(answer)