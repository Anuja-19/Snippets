#converting 12 hour time format to 24 hour format
s=input() #reads input
l=s.split(":")
if "PM" in s:          #checking for the input format
    if int(l[0])==12:
        l[0]="12"
    else:
        l[0]=str(int(l[0])+12)  #making necessary changes
if "AM" in s:           #checking for the input format
    if int(l[0])==12:
        l[0]="00"       #making necessary changes to the input string
l[-1]=l[-1][:2]
print(":".join(l))          
