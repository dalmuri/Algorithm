import sys

n = int(sys.stdin.readline())
stair = [0]
for _ in range(n):
    stair.append(int(sys.stdin.readline()))

point = [[0, 0] for _ in range(n + 1)]
# point[i][0] = 구간 [1, i]에서 stair[i]를 이전 계단과 연속하지 않고 밟을 때의 점수 최댓값
# point[i][1] = 구간 [1, i]에서 stair[i]를 이전 계단과 연속해서 밟을 때의 점수 최댓값
point[1] = [stair[1], stair[1]]

for i in range(2, n + 1):
    point[i][0] = max(point[i - 2]) + stair[i]
    point[i][1] = point[i - 1][0] + stair[i]

print(max(point[n]))