import sys

n = int(sys.stdin.readline())

num = list(map(int, list(str(n))))

for i in range(len(num) // 2, len(num)):
    num[i] = num[len(num) - 1 - i]

if n < int("".join(map(str, num))): print("".join(map(str, num)))
else:
    idx1 = (len(num) - 1) // 2
    num[idx1] += 1
    num[len(num) - 1 - idx1] = num[idx1]
    while num[idx1] == 10:
        num[idx1] = 0
        num[len(num) - 1 - idx1] = num[idx1]
        
        idx1 -= 1
        if idx1 < 0:
            num = [0] + num
            idx1 = 0
        num[idx1] += 1
        num[len(num) - 1 - idx1] = num[idx1]
    
    print("".join(map(str, num)))