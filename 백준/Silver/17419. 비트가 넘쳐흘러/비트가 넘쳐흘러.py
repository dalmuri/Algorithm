import sys

n = int(sys.stdin.readline())
k = sys.stdin.readline().strip()

answer = 0
for c in k:
    if c == '1':
        answer += 1

print(answer)