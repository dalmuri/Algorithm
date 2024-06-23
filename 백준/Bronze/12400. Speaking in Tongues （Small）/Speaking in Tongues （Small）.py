import sys

t = int(sys.stdin.readline())
dictionary = ['y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q']
for x in range(1, t + 1):
    text = sys.stdin.readline().strip()
    answer = "Case #" + str(x) + ": "
    for c in text:
        if c == ' ':
            answer += ' '
        else:
            answer += dictionary[ord(c) - ord('a')]
    
    print(answer)