def is_group_word(word):
    checked = [False for i in range(26)]
    for i in range(len(word)):
        chr = ord(word[i]) - ord("a")
        if not checked[chr]:
            checked[chr] = True
            continue
        
        if word[i - 1] != word[i]:
            return False
    return True

t = int(input())

answer = 0
for i in range(t):
    if is_group_word(input()):
        answer += 1
print(answer)
