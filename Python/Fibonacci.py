def fibb(n):
    if n==0 or n==1:
        return n
    else:
        return fibb(n-1)+fibb(n-2)


n=int(input("Enter the no. of terms: "))
print('The fibonaci series is :')
for i in range(n):
    print (fibb(i),end=" ")
