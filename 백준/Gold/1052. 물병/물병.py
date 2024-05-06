import sys

n, k = map(int, sys.stdin.readline().split())
binary = []
num_bottles = 0
while n > 0:
    binary.append(n & 1)
    num_bottles += n & 1
    n >>= 1

answer = 0
buying = False
for i in range(len(binary)):
    if buying:
        if binary[i] == 0:
            binary[i] = 1
            buying = False
        else:
            num_bottles -= 1
    
    if num_bottles <= k: break
    
    if not buying and binary[i] == 1:
        buying = True
        answer += 2**i

print(answer)