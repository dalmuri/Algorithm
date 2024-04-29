from itertools import product

def solution(users, emoticons):
    answer = [0, 0]
    for discount in product([10, 20, 30, 40], repeat=len(emoticons)):
        res = [0, 0]
        for user in users:
            price = 0
            for rate, e in zip(discount, emoticons):
                if rate >= user[0]:
                    price += e * (100 - rate) // 100
            if price >= user[1]: res[0] += 1
            else: res[1] += price
        
        if res[0] > answer[0] or (res[0] == answer[0] and res[1] > answer[1]): answer = res
    
    return answer