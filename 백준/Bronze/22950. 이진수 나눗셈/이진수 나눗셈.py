import sys

m = int(sys.stdin.readline())
num = list(map(int, list(sys.stdin.readline().strip())))
num.reverse()
k = int(sys.stdin.readline())

while len(num) > 0 and num[-1] == 0:
    num.pop()

if len(num) == 0:
    print("YES")
elif k < len(num) and num[:k].count(1) == 0:
    print("YES")
else:
    print("NO")