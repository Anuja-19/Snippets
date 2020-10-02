# Insertion Sort in Python, Time Complexity: O(n^2)

def displayElements(arr, n):
    for el in arr:
        print(el, " ", end = "")
    print()
    
def insertionSort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
  
        j = i - 1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key


if __name__ == "__main__":
    print("Enter number of array elements: ")
    n = int(input())
    print("Enter array elements: ")
    arr = list(map(int, input().split()))

    # Array before Insertion Sort
    print("Array before Insertion Sort: ")
    displayElements(arr, n)
    
    insertionSort(arr)

    # Array after Insertion Sort
    print("Array after Insertion Sort: ")
    displayElements(arr, n)

