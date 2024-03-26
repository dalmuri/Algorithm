x = int(input())

i = 1
cnt = 0

while i + cnt < x:
    cnt += 1
    i += cnt

if cnt % 2 == 0:
    r = cnt - (x - i)
    c = x - i
else:
    c = cnt - (x - i)
    r = x - i

print(r + 1, c + 1, sep="/")