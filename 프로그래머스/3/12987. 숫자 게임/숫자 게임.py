def solution(A, B):
    A.sort()
    B.sort()
    
    a = 0
    answer = 0
    for b in range(len(B)):
        if(A[a] < B[b]):
            answer += 1
            a += 1
    
    return answer