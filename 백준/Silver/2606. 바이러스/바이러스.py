def infect(com, infected, network):
    if infected[com]: return
    
    infected[com] = True
    
    for next in network[com]:
        infect(next, infected, network)


n = int(input())

network = [[] for i in range(n + 1)]
infected = [False] * (n + 1)

for i in range(int(input())):
    c1, c2 = map(int, input().split(" "))
    network[c1].append(c2)
    network[c2].append(c1)

infect(1, infected, network)

print(infected.count(True) - 1)