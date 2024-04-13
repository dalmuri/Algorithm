def wins(board, player):
    # row
    for r in range(3):
        if all(board[r][c] == player for c in range(3)):
            return True
    
    # col
    for c in range(3):
        if all(board[r][c] == player for r in range(3)):
            return True
    
    # diag \
    if all(board[i][i] == player for i in range(3)):
        return True
    
    # diag /
    if all(board[i][2 - i] == player for i in range(3)):
        return True
    
    return False

def solution(board):
    numO = sum(row.count("O") for row in board)
    numX = sum(row.count("X") for row in board)
    
    winO = wins(board, "O")
    winX = wins(board, "X")
    
    diff = numO - numX
    if diff < 0 or diff > 1:
        return 0
    if winO and winX:
        return 0
    if (winO and diff == 0) or (winX and diff == 1):
        return 0
    
    return 1