import math

def is_square(num):
    f, i = math.modf(math.sqrt(num))
    if f == 0:
        return True
    else:
        return False

def get_num(row, col, row_diff, col_diff, mat, n, m):
    now = mat[row][col]
    if row_diff == 0 and col_diff == 0:
        return [now]
    
    result = []
    row_idx = row + row_diff
    col_idx = col + col_diff
    while 0 <= row_idx < n and 0 <= col_idx < m:
        now += mat[row_idx][col_idx]
        result.append(now)
        result.append(now[::-1])
        row_idx += row_diff
        col_idx += col_diff
    return result
        
n, m = map(int, input().split(" "))

mat = [input() for i in range(n)]

nums = []
for row in range(n):
    for col in range(m):
        for row_diff in range(n):
            for col_diff in range(m):
                nums += get_num(row, col, row_diff, col_diff, mat, n, m)
                nums += get_num(row, col, -row_diff, col_diff, mat, n, m)
                nums += get_num(row, col, row_diff, -col_diff, mat, n, m)
                nums += get_num(row, col, -row_diff, -col_diff, mat, n, m)

answer = -1
for num in nums:
    now = int(num)
    if is_square(now):
        answer = max(answer, now)

print(answer)