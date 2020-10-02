def hanoi(disk,source,dest,spare):
    if disk==1:
        print("move disk %d from %s to %s"%(disk,source,dest))
        return
    else:
        hanoi(disk-1,source,spare,dest)
        print("move disk %d from %s to %s"%(disk,source,dest))
        hanoi(disk-1,spare,dest,source)
n=int(input("Enter number of disks:"))
hanoi(n,"a","b","c")