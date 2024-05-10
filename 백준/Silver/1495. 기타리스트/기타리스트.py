import sys

n, s, m = map(int, sys.stdin.readline().split())
v = list(map(int, sys.stdin.readline().split()))

volumes = [s]
for change in v:
    tmp = []
    for volume in volumes:
        if 0 <= volume + change <= m: tmp.append(volume + change)
        if 0 <= volume - change <= m: tmp.append(volume - change)
    
    if tmp:
        volumes = set(tmp)
    else:
        volumes = [-1]
        break

print(max(volumes))