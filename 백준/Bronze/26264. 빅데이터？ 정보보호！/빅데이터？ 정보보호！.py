import sys

n = int(sys.stdin.readline())
memo = sys.stdin.readline().strip()

s, b, i = 0, 0, 0
while i < len(memo):
    if memo[i] == 's':
        s += 1
        i += 8
    else:
        b += 1
        i += 7

if b < s: print("security!")
elif s < b: print("bigdata?")
else: print("bigdata? security!")