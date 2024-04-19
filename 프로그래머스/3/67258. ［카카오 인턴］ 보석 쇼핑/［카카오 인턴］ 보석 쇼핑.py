from collections import defaultdict

def solution(gems):
    answer = [1, len(gems)]
    
    buy = defaultdict(int)
    kinds = len(set(gems))
    
    start = 0
    end = -1
    num_kind = 0
    while end + 1 < len(gems): # end가 gems의 마지막에 도착하기 전까지 반복
        if num_kind < kinds:
            end += 1
            buy[gems[end]] += 1
            if buy[gems[end]] == 1:
                num_kind += 1
        else:
            buy[gems[start]] -= 1
            if buy[gems[start]] == 0:
                num_kind -= 1
            start += 1
        
        if num_kind == kinds:
            if end - start < answer[1] - answer[0]:
                answer[0] = start + 1
                answer[1] = end + 1
    
    while num_kind == kinds: # start를 1씩 증가하며 확인
        buy[gems[start]] -= 1
        if buy[gems[start]] == 0:
            num_kind -= 1
        start += 1
        
        if num_kind == kinds:
            if end - start < answer[1] - answer[0]:
                answer[0] = start + 1
                answer[1] = end + 1
    
    return answer