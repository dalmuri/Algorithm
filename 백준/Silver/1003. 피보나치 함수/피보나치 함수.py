import sys

cnt = [[] for _ in range(41)]
cnt[0] = [1, 0]
cnt[1] = [0, 1]
for i in range(2, 41):
    cnt[i] = [cnt[i - 2][0] + cnt[i - 1][0], cnt[i - 2][1] + cnt[i - 1][1]]

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    print(*cnt[n])