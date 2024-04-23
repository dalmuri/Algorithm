import sys

expression = sys.stdin.readline()

nums = []
operators = []

prev_oper = -1
for i in range(len(expression)):
    if expression[i] in ["+", "-"]:
        operators.append(expression[i])
        nums.append(int(expression[prev_oper + 1:i]))
        prev_oper = i
nums.append(int(expression[prev_oper + 1:]))

if "-" in operators:
     for i in range(operators.index("-") + 1, len(nums)):
        nums[i] *= -1  

print(sum(nums))