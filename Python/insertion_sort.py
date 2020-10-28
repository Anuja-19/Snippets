
"""
Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
So in beginning we compare the first two elements and sort them by comparing them. 
Then we pick the third element and find its proper position among the previous two sorted elements. 
This way we gradually go on adding more elements to the already sorted list by putting them in their proper position.
"""
def insertion_sort(InputList):
    for i in range(1, len(InputList)):
        j = i-1
        nxt_element = InputList[i]
        # Compare the current element with next one
        while (InputList[j] > nxt_element) and (j >= 0):
            InputList[j+1] = InputList[j]
            j=j-1
        InputList[j+1] = nxt_element


numbers = [19,2,31,45,30,11,121,27]
insertion_sort(numbers)
print(numbers)
