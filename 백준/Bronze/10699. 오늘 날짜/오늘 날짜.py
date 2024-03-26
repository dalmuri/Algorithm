import datetime as dt

now = dt.date.today()
print(str(now.year).zfill(4), str(now.month).zfill(2), str(now.day).zfill(2), sep="-")