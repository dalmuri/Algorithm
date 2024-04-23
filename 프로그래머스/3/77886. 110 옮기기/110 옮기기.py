def ext(x):
    stk = [];
    num1 = 0
    cnt = 0
    for c in x:
        if c == "1":
            stk.append(c);
            num1 += 1
        else:
            if num1 >= 2:
                stk.pop();
                stk.pop();
                num1 -= 2;
                cnt += 1
            else:
                stk.append(c)
                num1 = 0
    
    return ''.join(stk), cnt

def ins(x, cnt):
    idx_111 = x.find("111")
    if idx_111 != -1:
        return x[:idx_111] + "110" * cnt + x[idx_111:]
    else:
        idx_last0 = x.rfind("0")
        if idx_last0 != -1:
            return x[:idx_last0 + 1] + "110" * cnt + x[idx_last0 + 1:]
        else:
            return "110" * cnt + x

def solution(s):
    answer = []
    for x in s:
        new_x, cnt = ext(x)
        answer.append(ins(new_x, cnt))
    return answer