def solution(board, skill):
    n = len(board)
    m = len(board[0])
    prefix_sum = [[0] * (m + 1) for i in range(n + 1)]
    for sk in skill:
        degree = sk[5]
        if sk[0] == 1 : degree *= -1
        
        prefix_sum[sk[1]][sk[2]] += degree
        prefix_sum[sk[1]][sk[4] + 1] -= degree
        prefix_sum[sk[3] + 1][sk[2]] -= degree
        prefix_sum[sk[3] + 1][sk[4] + 1] += degree
    
    
    answer = 0
    for i in range(n):
        for j in range(m):
            if i > 0: prefix_sum[i][j] += prefix_sum[i - 1][j]
            if j > 0: prefix_sum[i][j] += prefix_sum[i][j - 1]
            if i > 0 and j > 0: prefix_sum[i][j] -= prefix_sum[i - 1][j - 1]
            
            if board[i][j] + prefix_sum[i][j] > 0:
                answer += 1
    
    return answer