#Selection Sort Function
function selectionsort!(arr)        #The function changes its argument hence bang(!) is used. 
    for i in 1:length(arr)          #Looping through array
        
        for j in i+1:length(arr)
            
            if arr[i] > arr[j]      #Swapping elements if next element is greater than current element
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
            end
        
        end
    
    end
    
    return arr                      #returning the sorted array
end

#Driver code

A = [4,3,5,1,2]         #input
println(A)              #printing array before sorting
selectionsort!(A)        #calling sorting function
println(A)              #printing array after sorting