import sys

n = int(sys.stdin.readline())
point = [0]
for _ in range(n):
    point.append(int(sys.stdin.readline()))

stair = [[0, 0] for _ in range(n + 1)]
# stair[i][0] = 구간 [1, i]에서 i계단을 이전 계단과 연속하지 않고 밟을 때의 점수 최댓값
# stair[i][1] = 구간 [1, i]에서 i계단을 이전 계단과 연속해서 밟을 때의 점수 최댓값
stair[1] = [point[1], point[1]]

for i in range(2, n + 1):
    stair[i][0] = max(stair[i - 2]) + point[i]
    stair[i][1] = stair[i - 1][0] + point[i]

print(max(stair[n]))