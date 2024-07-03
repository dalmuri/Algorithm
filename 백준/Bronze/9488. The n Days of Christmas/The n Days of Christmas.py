import sys

while True:
    num = int(sys.stdin.readline())
    if num == 0: break
    
    answer = (num * (num + 1) * (2 * num + 1) // 6 + num * (num + 1) // 2) // 2
    print(answer)