#Function to implement insertion sort

function insertion_sort!(arr)        #The function changes its argument hence bang(!) is used.
    #Looping through array
    for i in 2:length(arr)
        key = arr[i]
        j = i - 1
        while (j >= 1) && (key < arr[j])    #Moving elements greater than key to one position ahead of their current position.
            arr[j + 1] = arr[j]
            j = j - 1
        end
        arr[j + 1] = key
    end
end


#Driver Code
arr = [2, 1, 4, 3, 5, 6]        #input
println(arr)                    #printing array before sorting
insertion_sort!(arr)            #calling sorting function
println(arr)                    #printing sorted array