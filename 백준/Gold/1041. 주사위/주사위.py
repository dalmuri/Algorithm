comb2 = [[0, 1], [0, 2], [0, 3], [0, 4], [1, 2], [1, 3], [1, 5], [2, 4], [2, 5], [3, 4], [3, 5], [4, 5]]
comb3 = [[0, 1, 2], [0, 1, 3], [0, 2, 4], [0, 3, 4], [1, 2, 5], [1, 3, 5], [2, 4, 5], [3, 4, 5]]

def get_min(side, numbers):
    if side == 1:
        return min(numbers)
    elif side == 2:
        result = 301
        for comb in comb2:
            result = min(result, numbers[comb[0]] + numbers[comb[1]])
        return result
    elif side == 3:
        result = 301
        for comb in comb3:
            result = min(result, numbers[comb[0]] + numbers[comb[1]] + numbers[comb[2]])
        return result
    elif side == 5:
        return sum(numbers) - max(numbers)
    else:
        return 0

n = int(input())

numbers = list(map(int, input().split(" ")))

if n == 1:
    print(get_min(5, numbers))
else:
    num_side1 = (n - 2) * (n - 1) * 4 + (n - 2)**2
    num_side2 = (n - 1) * 4 + (n - 2) * 4
    num_side3 = 4
    answer = get_min(1, numbers) * num_side1 + get_min(2, numbers) * num_side2 + get_min(3, numbers) * num_side3
    print(answer)