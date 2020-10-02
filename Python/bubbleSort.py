#Bubble Sort Function
def bubble_sort(a):
    #looping through Array
    for i in range(len(arr)-1):
        for j in range(len(arr)-1-i):
            #swap if current element is greater than next element
            if a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
    return a
#driver Code
#insert space separeted input
arr = list(map(int, input().split()))
#array Before Sorting
print("Before sorting",arr)
#array after Sorting
print("After Sorting",bubble_sort(arr))