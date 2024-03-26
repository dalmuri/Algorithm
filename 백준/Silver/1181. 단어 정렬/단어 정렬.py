t = int(input())

s = set()
for i in range(t):
    s.add(input())

arr = list(s)
arr.sort(key= lambda a: (len(a), a))
for i in range(len(arr)):
    print(arr[i])