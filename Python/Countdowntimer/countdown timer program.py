#!/usr/bin/env python
# coding: utf-8

# In[12]:


import time   
import datetime


# Get the input in dd/mm/year format
print('Enter the date in dd mm year as space separated integers')
[dd,mm,year]=list(map(int,input().split()))

#Get today's date using datetime module
today=datetime.datetime.now().date()

#convert the date as date/month/year format
today_date = today.strftime("%d/%m/%Y")
[ddtoday,mmtoday,yeartoday]=list(map(int,today_date.split('/')))

# Get the time object from datetime module
now = datetime.datetime.now().time() 

#convert the time as hour/minute/second format
now_time = now.strftime("%H:%M:%S")
[hr,mins,sec]=list(map(int,now_time.split(':')))

#Using timedelta to get the difference between two dates
given_date = datetime.datetime(year,mm,dd,00,00,00) 
today_date = datetime.datetime(yeartoday,mmtoday,ddtoday,hr,mins,sec) 
diff = given_date-today_date


#From the output of timedelta function, calculate the remaining number of days, hours, minutes and seconds
diff_string=str(diff)
[a,b]=diff_string.split(',')
dayss=int(a.split(' ')[0])
[h,m,s]=list(map(int,b.split(':')))

#If any of the values is negative, that means user entered a past date which is not valid for a countdowntimer
if (dayss<0) or (h<0) or (m<0) or (s<0):
    print('The given date is not a valid date')
    
#If all the values are positive, the timer can run  
else:
    
    #Calculate the total number of seconds 
    total=(dayss*24*60*60)+diff.seconds 
    
    #the timer has to run until the total no. of seconds become zero
    #Interrupt the kernel to stop the timer in between
    while total:
        
        #calculate the no. of seconds, minutes, hours,days using the total no. of seconds
        mz,sz=divmod(total,60)   
        hz,mz=divmod(mz,60)
        dz,hz=divmod(hz,24)
        
        #Display the timer in the days, hours, minutes,seconds format
        timer = '{:02d} days :{:02d} hours :{:02d} minutes : {:02d} seconds'.format(dz,hz,mz,sz) 
        
        print(timer, end="\r") 
        
        #Pause the timer for 1 second
        time.sleep(1)
        
        #Decrement the total number of seconds by 1
        total=total-1







