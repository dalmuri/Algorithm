import sys

n = int(sys.stdin.readline())
cranes = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
boxes = list(map(int, sys.stdin.readline().split()))

cranes.sort(reverse=True)
boxes.sort(reverse=True)

answer = 0
if cranes[0] < boxes[0]:
    answer = -1
else:
    while boxes:
        for crane in cranes:
            for i, box in enumerate(boxes):
                if box <= crane:
                    del boxes[i]
                    break
        answer += 1

print(answer)