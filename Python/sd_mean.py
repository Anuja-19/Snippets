import math
def mean(l):
    x=sum(l)
    return round(x/len(l),2)

def sqr(x):
    return x*x

def sd(l):

    list1=list(map(sqr,l))
    s=sum(list1)
    s=s/len(list1)-sqr(mean(l))
    return math.sqrt(s)

l=[1,2,3,4,5]
print(mean(l))
print(round(sd(l),4))
