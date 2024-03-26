import datetime

def is_gg(day1, day2):
    if(day2.year - day1.year > 1000):
        return True
    elif(day2.year - day1.year == 1000):
        if(day2.month > day1.month):
            return True
        elif(day2.month == day1.month and day2.day >= day1.day):
            return True
    
    return False

y, m, d = map(int, input().split(" "))
day1 = datetime.date(year= y, month= m, day= d)

y, m, d = map(int, input().split(" "))
day2 = datetime.date(year= y, month= m, day= d)

if(is_gg(day1, day2)):
    print("gg")
else:
    print(f"D-{(day2 - day1).days}")