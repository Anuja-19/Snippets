# Python Implementation of Heap Sort 
# Author : Aditya Mathur
# Date : 4 Oct 2020

def heapify(arr, n, i): 
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
  
    # See if left child of root exists and is 
    # greater than root 
    if left< n and arr[i] < arr[left]: 
        largest = left
  
    # See if right child of root exists and is 
    # greater than root 
    if right < n and arr[largest] < arr[right]: 
        largest = right
  
    # Change root, if needed 
    if largest != i: 
        arr[i],arr[largest] = arr[largest],arr[i]
  
        # Heapify the root. 
        heapify(arr, n, largest) 

def heapSort(arr):
    n = len(arr)

    # Max Heap
    # Since last parent will be at ((n//2)-1) we can start at that location
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements 
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0) 


# Testing Code
arr = [ 56, 77, 2, 15, 30, 9]
heapSort(arr) 
print(" ".join(map(str, arr)))
