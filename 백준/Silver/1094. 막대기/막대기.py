import heapq

def cut(x, hq):
    n = heapq.heappop(hq) / 2
    if sum(hq) + n == x:
        print(len(hq) + 1)
    elif sum(hq) + n > x:
        heapq.heappush(hq, n)
        cut(x, hq)
    else:
        heapq.heappush(hq, n)
        heapq.heappush(hq, n)
        cut(x, hq)
    

x = int(input())

if x == 64:
    print(1)
else:
    cut(x, [64])