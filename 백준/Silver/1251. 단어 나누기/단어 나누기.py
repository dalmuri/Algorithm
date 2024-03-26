word = input()

min1_idx = 0
min1 = word[min1_idx]
for i in range(1, len(word) - 2):
    w = word[i : : -1]
    if(w < min1):
        min1 = w
        min1_idx = i
        
min2_idx = min1_idx + 1
min2 = word[min2_idx]
for i in range(min1_idx + 2, len(word) - 1):
    w = word[i : min1_idx : -1]
    if(w < min2):
        min2 = w
        min2_idx = i

print(min1 + min2 + word[: min2_idx : -1])