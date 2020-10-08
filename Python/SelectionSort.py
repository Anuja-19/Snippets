# Selection Sort in Python, Time Complexity: O(n^2)

def displayElements(arr, n):
    for el in arr:
        print(el, " ", end = "")
    print()
    
def selectionSort(arr, n):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
                
        # Swap the minimum element with the first element in current array
        arr[i], arr[min_index] = arr[min_index], arr[i] 


if __name__ == "__main__":
    print("Enter number of array elements: ")
    n = int(input())
    print("Enter array elements: ")
    arr = list(map(int, input().split()))

    # Array before Selection Sort
    print("Array before Selection Sort: ")
    displayElements(arr, n)
    
    selectionSort(arr, n)

    # Array after Selection Sort
    print("Array after Selection Sort: ")
    displayElements(arr, n)
