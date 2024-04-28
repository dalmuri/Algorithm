def solution(n, lost, reserve):
    clothes = [0] + [1] * n + [0]
    for r in reserve: clothes[r] += 1
    for l in lost: clothes[l] -= 1
    
    answer = 0
    for i in range(1, n + 1):
        if clothes[i] >= 1:
            answer += 1
            continue
        
        if clothes[i - 1] > 1:
            clothes[i - 1] -= 1
            answer += 1
        elif clothes[i + 1] > 1:
            clothes[i + 1] -= 1
            answer += 1
            
    return answer