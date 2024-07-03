import sys

x = int(sys.stdin.readline())
y = int(sys.stdin.readline())

for i in range(x, y + 1, 60):
    print("All positions change in year " + str(i))