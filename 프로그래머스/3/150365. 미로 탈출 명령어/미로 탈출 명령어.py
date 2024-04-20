def solution(n, m, x, y, r, c, k):
    move = [0, 0, 0, 0] # down, left, right, up
    word = ["d", "l", "r", "u"]
    dir = [[1, 0], [0, -1], [0, 1], [-1, 0]]
    cnt = k
    if r - x > 0:
        move[0] = r - x
        cnt -= r - x
    else:
        move[3] = x - r
        cnt -= x - r
    
    if c - y > 0:
        move[2] = c - y
        cnt -= c - y
    else:
        move[1] = y - c
        cnt -= y - c
    
    if cnt < 0 or (cnt & 1) == 1: return "impossible"
    
    answer = ""
    
    while k > 0:
        for i in range(4):
            if move[i] > 0:
                answer += word[i]
                k -= 1
                x += dir[i][0]
                y += dir[i][1]
                move[i] -= 1
                break
            
            if move[i] == 0 and cnt > 0 and 0 < x + dir[i][0] <= n and 0 < y + dir[i][1] <= m:
                answer += word[i]
                k -= 1
                x += dir[i][0]
                y += dir[i][1]
                move[3 - i] += 1
                cnt -= 2
                break
    
    return answer