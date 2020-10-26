#heap sort

function heapify(arr, size, start)
    
    max = start
    l = 2 * start
    r = l + 1
    
    if r <= size && arr[max] < arr[r]
        max = r
    end
    if l <= size && arr[max] < arr[l]
        max = l
    end
    
    if max != start
        arr[max], arr[start] = arr[start], arr[max]
        heapify(arr, size, max)
    end
end

n = 20                   #length of array   
a = 10
b = 100
arr = rand(a:b, n)       #array of random numbers from a to b

println("Random Number Array")
println(arr)

#Building max heap
for i in div(n, 2):-1:1
    heapify(arr, n, i)
end

#swapping first element with the last element
len = n
for i in n:-1:2
    global len
    arr[i], arr[1] = arr[1], arr[i]
    len = len - 1
    heapify(arr, len, 1)
end

println("Sorted Array")
println(arr)