import sys

def init_h(low, has_height):
    while has_height[-1] > low:
        has_height.pop()


n = int(sys.stdin.readline())

skyline = []
max_h = 0
for i in range(n):
    skyline.append(list(map(int, sys.stdin.readline().split())))
    max_h = max(max_h, skyline[i][1])

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