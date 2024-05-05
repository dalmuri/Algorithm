import sys

n, m = map(int, sys.stdin.readline().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, list(sys.stdin.readline().strip()))))


def get_len():
    dist = min(n, m) - 1
    while dist > 0:
        for i in range(0, n):
            if i + dist >= n: break
            for j in range(0, m):
                if j + dist >= m: break
                if arr[i][j] == arr[i][j + dist] == arr[i + dist][j] == arr[i + dist][j + dist]:
                    return dist + 1
        dist -= 1
    return 1

print(get_len()**2)