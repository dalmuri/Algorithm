a, b = map(int, input().split(" "))

num_factor = [0 for i in range(b + 1)]
num_factor[0] = -1
num_factor[1] = -1
for i in range(2, b // 2 + 1):
    if num_factor[i] == 0:
        j = 2 * i
        while j <= b:
            num = j
            while num % i == 0:
                num_factor[j] += 1
                num /= i
            j += i

answer = 0
for i in range(a, b + 1):
    if num_factor[num_factor[i]] == 0:
        answer += 1

print(answer)