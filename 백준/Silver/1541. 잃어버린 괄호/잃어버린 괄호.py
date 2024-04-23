import sys

expression = sys.stdin.readline()

answer = 0

prev_oper = -1
is_plus = True
for i in range(len(expression)):
    if expression[i] in ["+", "-"]:
        answer += int(expression[prev_oper + 1:i]) if is_plus else -int(expression[prev_oper + 1:i])
        
        if expression[i] == "-":
            is_plus = False
        prev_oper = i

answer += int(expression[prev_oper + 1:]) if is_plus else -int(expression[prev_oper + 1:])

print(answer)
