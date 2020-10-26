import calendar

birth_year=input("Enter your birth year:")
birth_month=input("Enter your birth month:")
birth_date=input("Enter the birth date:")

dates=0
presant_year=2020
presant_month=9
presant_day=2
date1=0
date2=0
leap_day=0
for m in range(1,presant_month):
    date1=date1+calendar.monthlen(presant_year,m)
    m+=1


for m in range(int(birth_month),12):
    date2=date2+calendar.monthlen(int(birth_year),m)
    m=m+1



    if presant_day>int(birth_date):
        date3=presant_day-int(birth_date)
    else:
        date3=int(birth_date)-presant_day


for y in range(int(birth_year),presant_year):
    if calendar.isleap(y)==True:
        leap_day=leap_day+1
y=y+1



cal_date=date1+date2 +date3
years=2020-int(birth_year)
if cal_date>365:
    cal_date = abs(365+leap_day+1-(date1 + date2 + date3))


else:
    years = 2020 - int(birth_year) - 1
    cal_date = date1 + date2 + date3-leap_day
print('years '+ str(years) +' and dates ' + str(cal_date))





