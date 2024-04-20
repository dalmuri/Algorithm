from math import sqrt, floor, ceil

def solution(r1, r2):
    r1r1 = r1 ** 2
    r2r2 = r2 ** 2
    answer = 0
    
    for x in range(r1):
        xx = x ** 2
        
        big = floor(sqrt(r2r2 - xx))
        small = ceil(sqrt(r1r1 - xx))
        answer += big - small + 1
    
    for x in range(r1, r2):
        xx = x ** 2
        answer += floor(sqrt(r2r2 - xx))
    
    return answer * 4