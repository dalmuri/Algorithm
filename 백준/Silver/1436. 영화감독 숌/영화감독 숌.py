n = int(input())

num = 666
cnt = 1
while(cnt < n):
    num += 1
    if str(num).__contains__("666"):
        cnt += 1

print(num)