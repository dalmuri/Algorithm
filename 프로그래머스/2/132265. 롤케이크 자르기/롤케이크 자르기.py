from collections import Counter

def solution(topping):
    topping_l = set()
    topping_r = Counter(topping)
    kind_r = len(topping_r)
    
    answer = 0
    for t in topping:
        topping_l.add(t)
        
        topping_r[t] -= 1
        if topping_r[t] == 0:
            kind_r -= 1
        
        if len(topping_l) == kind_r:
            answer += 1
    
    return answer