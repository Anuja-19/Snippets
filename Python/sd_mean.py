import math
def mean(l):
    sum=0
    for i in range(len(l)):
        sum=sum+l[i]
    return round(sum/len(l),2)

def sqr(x):
    return x*x

def sd(l):
    s=0
    list1=list(map(sqr,l))
    for i in range(len(list1)):
        s=s+list1[i]
    s=s/len(list1)-sqr(mean(l))
    return math.sqrt(s)

l=[1,2,3,4,5]
print("Mean: %.2f"%mean(l))
print("Standard Deviation: %f"%round(sd(l),4))