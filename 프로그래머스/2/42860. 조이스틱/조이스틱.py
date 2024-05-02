def alphabet(c):
    return min(ord(c) - ord("A"), ord("Z") - ord(c) + 1)

def solution(name):
    answer = len(name) - 1
    for i in range(len(name)):
        j = i + 1
        while j < len(name) and name[j] == "A": j += 1
        
        '''
        0_____iAAAAAAAj__
        0에서 오른쪽으로 i로 갔다가 왼쪽으로 j까지 이동횟수: i * 2 + (len(name) - j)
        0에서 왼쪽으로 j로 갔다가 오른쪽으로 i까지 이동횟수: (len(name) - j) * 2 + i
        '''
        answer = min(answer, i + len(name) - j + min(i, len(name) - j))
    
    for c in name:
        answer += alphabet(c)
    return answer