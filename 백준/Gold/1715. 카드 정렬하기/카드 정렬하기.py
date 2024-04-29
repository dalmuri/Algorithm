import sys
from heapq import heappush, heappop

n = int(sys.stdin.readline())

cards = []
for _ in range(n):
    heappush(cards, int(sys.stdin.readline()))

answer = 0
while len(cards) >= 2:
    a = heappop(cards)
    b = heappop(cards)
    
    answer += a + b
    heappush(cards, a + b)

print(answer)