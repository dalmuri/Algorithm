import sys

n = int(sys.stdin.readline())

cnt = [0] * 26
for _ in range(n):
    word = list(sys.stdin.readline().strip())
    for i in range(len(word)):
        c = word[len(word) - 1 - i]
        cnt[ord(c) - ord('A')] += 10**i

cnt.sort(reverse=True)

answer = 0
for i in range(10):
    answer += cnt[i] * (9 - i)

print(answer)