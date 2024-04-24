import sys

n = int(sys.stdin.readline())

skyline = []
for i in range(n):
    skyline.append(list(map(int, sys.stdin.readline().split())))

has_height = [0] # stack

answer = 0
for idx, h in skyline:
    if has_height[-1] < h:
        answer += 1
        has_height.append(h)
    else:
        while has_height[-1] > h:
            has_height.pop()
        
        if has_height[-1] < h:
            answer += 1
            has_height.append(h)

print(answer)