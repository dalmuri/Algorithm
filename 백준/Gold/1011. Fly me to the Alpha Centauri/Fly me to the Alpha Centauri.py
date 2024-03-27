def calc(x, y):
    dist = y - x
    if dist == 1:
        return 1
    
    result = 0
    now = 1
    while dist > 0:
        if dist >= now:
            result += 1
            dist -= now
        if dist >= now:
            result += 1
            dist -= now
        
        if 0 < dist and dist <= now:
            result += 1
            dist = 0
            break
        now += 1
    return result

t = int(input())

for i in range(t):
    x, y = map(int, input().split(" "))
    print(calc(x, y))
    