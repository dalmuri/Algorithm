def solution(n):
    answer = []
    def move(size, now, to_move):
        if size == 0: return
        
        move(size - 1, now, 6 - now - to_move)
        answer.append([now, to_move])
        move(size - 1, 6 - now - to_move, to_move)
    
    move(n, 1, 3)
    return answer