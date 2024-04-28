def solution(n, lost, reserve):
    lost.sort()
    clothes = [0] + [1] * n + [0]
    for r in reserve: clothes[r] += 1
    for l in lost: clothes[l] -= 1
    
    answer = n - len(lost)
    for l in lost:
        if clothes[l] == 1:
            answer += 1
            continue
        
        if clothes[l - 1] > 1:
            clothes[l - 1] -= 1
            answer += 1
        elif clothes[l + 1] > 1:
            clothes[l + 1] -= 1
            answer += 1
            
    return answer