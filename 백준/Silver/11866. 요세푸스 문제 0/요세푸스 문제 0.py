import sys

n, k = map(int, sys.stdin.readline().split())

people = list(range(1, n + 1))
answer = []

now = 0
while people:
    now = (now + k - 1) % len(people)
    answer.append(people[now])
    del people[now]
    if now >= len(people):
        now = 0

print("<", end="")
print(*answer, sep=", ", end="")
print(">")