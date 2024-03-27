def matches(signal):
    if len(signal) >= 2 and signal[0:2] == "01":
        if 2 == len(signal):
            return True
        else:
            return matches(signal[2:])
    elif len(signal) >= 3 and signal[0:3] == "100":
        idx = 3
        while idx < len(signal) and signal[idx] == "0":
            idx += 1
        if idx == len(signal):
            return False
        while idx < len(signal) and signal[idx] == "1":
            idx += 1
        
        if idx == len(signal):
            return True
        else:
            return matches(signal[idx:]) or (False if signal[idx - 2] == "0" else matches(signal[idx - 1:]))
    else:
        return False
            

t = int(input())

for i in range(t):
    signal = input()
    if matches(signal):
        print("YES")
    else:
        print("NO")