def calc(l, r, answer):
    if len(l) <= 0:
        return answer
    
    if l[0] < r[0]:
        return answer
    elif l[0] != "8":
        return calc(l[1:], r[1:], answer)
    else:
        return calc(l[1:], r[1:], answer + 1)


l, r = input().split(" ")

if len(l) < len(r):
    print(0)
else:
    print(calc(l, r, 0))