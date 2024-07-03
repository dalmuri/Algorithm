import sys

t = int(sys.stdin.readline())

for _ in range(t):
    sentence = sys.stdin.readline().strip() + " "
    answer = 0
    
    while sentence:
        if sentence.startswith("u ") or sentence.startswith("ur ") or sentence.startswith("would of ") or sentence.startswith("should of "):
            answer += 10
        
        next = sentence.find(" ")
        if sentence[:next].find("lol") != -1:
            answer += 10

        sentence = sentence[next + 1:]
    
    print(answer)