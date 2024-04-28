from collections import defaultdict

def solution(topping):
    topping_l = defaultdict(int)
    topping_r = defaultdict(int)
    kind_l = 0
    kind_r = 0
    for t in topping:
        topping_r[t] += 1
        if topping_r[t] == 1:
            kind_r += 1
    
    answer = 0
    for t in topping:
        topping_l[t] += 1
        if topping_l[t] == 1:
            kind_l += 1
        
        topping_r[t] -= 1
        if topping_r[t] == 0:
            kind_r -= 1
        
        if kind_l == kind_r:
            answer += 1
    
    return answer