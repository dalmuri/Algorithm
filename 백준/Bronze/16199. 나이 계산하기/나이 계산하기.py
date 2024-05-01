import sys

birth = list(map(int, sys.stdin.readline().split()))
today = list(map(int, sys.stdin.readline().split()))

print(today[0] - birth[0] if today[1] > birth[1] or (today[1] == birth[1] and today[2] >= birth[2]) else today[0] - birth[0] - 1)
print(today[0] - birth[0] + 1)
print(today[0] - birth[0])