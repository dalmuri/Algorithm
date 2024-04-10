import sys
sys.setrecursionlimit(10000) # 재귀 한도 증가

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]]

def search(row, col, n, m, visited, maps):
    if row < 0 or row >= n or col < 0 or col >= m:
        return 0
    if maps[row][col] == "X":
        return 0
    if visited[row][col]:
        return 0
    
    visited[row][col] = True
    result = int(maps[row][col])
    for d in direction:
        result += search(row + d[0], col + d[1], n, m, visited, maps)
    
    return result

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    visited = [([False] * m) for i in range(n)]
    
    answer = []
    for r in range(n):
        for c in range(m):
            days = search(r, c, n, m, visited, maps)
            if days > 0:
                answer.append(days)
    
    answer.sort()
    return answer if answer else [-1]