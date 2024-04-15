import sys
sys.setrecursionlimit(10000)

def calc(seller_idx, profit, parents, answer):
    to_give = profit // 10
    mine = profit - to_give
    
    answer[seller_idx] += mine
    if parents[seller_idx] != -1 and to_give > 0:
        calc(parents[seller_idx], to_give, parents, answer)

def solution(enroll, referral, seller, amount):
    idxs = dict((enr, i) for i, enr in enumerate(enroll))
    idxs["-"] = -1
    parents = [idxs[ref] for ref in referral]
    
    answer = [0] * len(enroll)
    for sel, amt in zip(seller, amount):
        calc(idxs[sel], amt * 100, parents, answer)
    
    return answer