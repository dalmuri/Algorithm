import sys
sys.setrecursionlimit(100000)

def calc(seller_idx, profit, parents, answer):
    to_give = profit // 10
    mine = profit - to_give
    
    answer[seller_idx] += mine
    if parents[seller_idx] != -1 and to_give > 0:
        calc(parents[seller_idx], to_give, parents, answer)

def solution(enroll, referral, seller, amount):
    idxs = {}
    parents = [-1] * len(enroll)
    for i in range(len(enroll)):
        idxs[enroll[i]] = i
        
        if referral[i] != "-":
            parents[i] = idxs[referral[i]]
    
    answer = [0] * len(enroll)
    for i in range(len(seller)):
        calc(idxs[seller[i]], amount[i] * 100, parents, answer)
    
    return answer