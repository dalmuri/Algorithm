import sys

def calc(num):
    result = num
    while num:
        result += num % 10
        num //= 10
    return result


n = int(sys.stdin.readline())

answer = 1
while answer <= n:
    if calc(answer) == n:
        break
    answer += 1

if answer > n:
    answer = 0
print(answer)