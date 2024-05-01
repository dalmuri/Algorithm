import sys
from collections import defaultdict

dictionary = []
while True:
    word = sys.stdin.readline().strip()
    if word == "-":
        break
    
    d = defaultdict(int)
    for w in word:
        d[w] += 1
    dictionary.append(d)

while True:
    word = sys.stdin.readline().strip()
    if word == "#":
        break
    
    puzzle = defaultdict(int)
    res = defaultdict(int)
    for w in word:
        puzzle[w] += 1
        res[w] = 0
    
    for word_dict in dictionary:
        if all(word_dict[key] <= puzzle[key] for key in word_dict):
            for key in word_dict:
                res[key] += 1
    
    min_cnt = 200_001
    min_char = []
    max_cnt = -1
    max_char = []
    for c in res:
        if res[c] < min_cnt:
            min_cnt = res[c]
            min_char = [c]
        elif res[c] == min_cnt:
            min_char.append(c)
        
        if res[c] > max_cnt:
            max_cnt = res[c]
            max_char = [c]
        elif res[c] == max_cnt:
            max_char.append(c)
    
    min_char.sort()
    max_char.sort()
    
    print("".join(min_char) + " " + str(min_cnt) + " " + "".join(max_char) +  " " + str(max_cnt))