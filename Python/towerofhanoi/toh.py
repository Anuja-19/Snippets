def hanoi(disk,A,C,B):
    if disk==1:
        print("move disk %d from %s to %s"%(disk,A,C))
        return
    else:
        hanoi(disk-1,A,B,C)
        print("move disk %d from %s to %s"%(disk,A,C))
        hanoi(disk-1,B,C,A)
n=int(input("Enter number of disks:"))
hanoi(n,"a","b","c")