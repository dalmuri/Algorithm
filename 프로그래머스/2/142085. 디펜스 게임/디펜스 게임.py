import heapq

def solution(n, k, enemy):
    answer = 0
    defence = []
    for i in range(len(enemy)):
        n -= enemy[i]
        heapq.heappush(defence, -enemy[i])
        if n < 0:
            if k <= 0:
                break
            
            k -= 1
            n += -heapq.heappop(defence)
        
        answer += 1
            
    return answer