import sys

def str2int(time):
    h = int(time[0:2])
    m = int(time[3:5])
    s = int(time[6:])
    return h * 3600 + m * 60 + s


def int2str(time):
    h = time // 3600
    time %= 3600
    m = time // 60
    time %= 60
    s = time
    return str(h).zfill(2) + ":" + str(m).zfill(2) + ":" + str(s).zfill(2)


now = str2int(sys.stdin.readline().strip())
start = str2int(sys.stdin.readline().strip())

if now > start:
    start += 24 * 3600

print(int2str(start - now))