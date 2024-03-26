t = int(input())

words = []
for i in range(t):
    word = input()
    words.append(word)

words.sort()
is_prefix = [False for i in range(len(words))]

for i in range(len(words) - 1):
    for j in range(i + 1, len(words)):
        if words[j] < words[i] + "{":
            is_prefix[i] = True

answer = 0
for i in range(len(is_prefix)):
    if not is_prefix[i]:
        answer += 1

print(answer)