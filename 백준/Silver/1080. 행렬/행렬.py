def change(arr, r, c):
    for i in range(3):
        for j in range(3):
            arr[r + i][c + j] = (arr[r + i][c + j] + 1) % 2

def calc(arr1, arr2, row, col):
    if row < 3 or col < 3:
        if arr1 == arr2:
            return 0
        else:
            return -1
    
    result = 0
    for r in range(row):
        for c in range(col):
            if arr1[r][c] != arr2[r][c]:
                if r < row - 2 and c < col - 2:
                    change(arr1, r, c)
                    result += 1
                else:
                    return -1
    return result


row, col = map(int, input().split(" "))

arr1 = []
for i in range(row):
    tmp = []
    c = input()
    for j in range(col):
        tmp.append(int(c[j]))
    arr1.append(tmp)

arr2 = []
for i in range(row):
    tmp = []
    c = input()
    for j in range(col):
        tmp.append(int(c[j]))
    arr2.append(tmp)

print(calc(arr1, arr2, row, col))