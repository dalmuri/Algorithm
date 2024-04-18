import sys

def check(s):
    stk = []
    for c in s:
        if c == "(":
            stk.append("(")
        elif c == "[":
            stk.append("[")
        elif c == ")":
            if stk and stk[-1] == "(":
                stk.pop()
            else:
                return "no"
        elif c == "]":
            if stk and stk[-1] == "[":
                stk.pop()
            else:
                return "no"
    
    if stk:
        return "no"
    else:
        return "yes"    
    
while True:
    line = sys.stdin.readline()
    if line[0] == ".": break
    
    print(check(line))