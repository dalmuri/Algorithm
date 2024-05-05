import sys

height = [int(sys.stdin.readline()) for _ in range(9)]
height.sort()
diff = sum(height) - 100

def search(diff):
    for i in range(8):
        for j in range(i + 1, 9):
            if height[i] + height[j] > diff: break
            if height[i] + height[j] == diff:
                return i, j

a, b = search(diff)
for i in range(9):
    if i == a or i == b: continue
    print(height[i])