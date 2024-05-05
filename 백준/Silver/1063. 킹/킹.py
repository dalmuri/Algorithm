import sys

pos_king, pos_stone, n = sys.stdin.readline().split()
king = [ord(pos_king[0]) - ord('A'), int(pos_king[1]) - 1]
stone = [ord(pos_stone[0]) - ord('A'), int(pos_stone[1]) - 1]

for _ in range(int(n)):
    command = sys.stdin.readline().strip()
    next = [0, 0]
    
    if command == "R":
        next = [1, 0]
    elif command == "L":
        next = [-1, 0]
    elif command == "B":
        next = [0, -1]
    elif command == "T":
        next = [0, 1]
    elif command == "RT":
        next = [1, 1]
    elif command == "LT":
        next = [-1, 1]
    elif command == "RB":
        next = [1, -1]
    else:
        next = [-1, -1]
    
    if 0 <= king[0] + next[0] < 8 and 0 <= king[1] + next[1] < 8:
        if king[0] + next[0] == stone[0] and king[1] + next[1] == stone[1]:
            if 0 <= stone[0] + next[0] < 8 and 0 <= stone[1] + next[1] < 8:
                king[0] += next[0]
                king[1] += next[1]
                stone[0] += next[0]
                stone[1] += next[1]
        else:
            king[0] += next[0]
            king[1] += next[1]

print(chr(ord('A') + king[0]), king[1] + 1, sep="")
print(chr(ord('A') + stone[0]), stone[1] + 1, sep="")