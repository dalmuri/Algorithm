import sys
from collections import defaultdict

n = int(sys.stdin.readline())
check = defaultdict(int)
answer = 0

for _ in range(n):
    chat = sys.stdin.readline().strip()
    if chat == "ENTER":
        check = defaultdict(int)
        continue
    
    if check[chat] == 0:
        answer += 1
        check[chat] += 1

print(answer)