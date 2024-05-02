def alphabet(c):
    return min(ord(c) - ord("A"), ord("Z") - ord(c) + 1)

def solution(name):
    answer = len(name) - 1
    
    A_start, A_end = 0, 0
    long_A = [A_start, A_end] # [A_start, A_end) 구간이 모두 A
    
    new_name = name + name
    while A_start < len(name):
        if name[A_start] == "A":
            A_end = A_start + 1
            while A_end < len(new_name) and new_name[A_end] == "A": A_end += 1
            
            if long_A[1] - long_A[0] < A_end - A_start:
                long_A = [A_start, A_end]
            
            A_start = A_end + 1
        else: A_start += 1
    
    i = max(0, long_A[0] - 1)
    j = long_A[1]
    
    if j > len(name): # AAA______AA
        answer = min(answer, min(i, len(name) - (j - len(name))))
    elif long_A != [0, 0]: # name에 A가 하나라도 있는 경우
        answer = min(answer, i + len(name) - j + min(i, len(name) - j))
        '''
        0_____iAAAAAAAj__
        0에서 오른쪽으로 i로 갔다가 왼쪽으로 j까지 이동횟수: i * 2 + (len(name) - j)
        0에서 왼쪽으로 j로 갔다가 오른쪽으로 i까지 이동횟수: (len(name) - j) * 2 + i
        '''
    
    for c in name:
        answer += alphabet(c)
    return answer