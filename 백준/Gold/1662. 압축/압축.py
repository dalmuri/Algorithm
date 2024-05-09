import sys

def unzip(string):
    result = 0
    stk = []
    for i in range(len(string)):
        if string[i] == '(':
            if len(stk) == 0: result -= 1
            stk.append(i)
        elif string[i] == ')':
            left = stk.pop()
            if len(stk) == 0:
                result += unzip(string[left + 1:i]) * int(string[left - 1])
        elif not stk:
            result += 1
    return result


s = sys.stdin.readline().strip()
print(unzip(s))