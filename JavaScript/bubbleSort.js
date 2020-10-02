// bubble-Sort function
function bubbleSort(ar) {
    //initializing temp variable to swap
    let temp;
    //looping through array
    for (let i = 0; i < ar.length-1; i++) {
        for (let j = 0; j < ar.length-i-1; j++) {
            if (ar[j]>ar[j+1]) {
                //swapping array elements if current element is greater than next element
                // [ar[j],ar[j+1]]=[ar[j+1],ar[j]]  -->can use this swapping technique as well
                temp=ar[j] ;
                ar[j]=ar[j+1];
                ar[j+1]=temp;

            }            
        }
        
    }
    return ar;
}

//Driver Code

//taking input
arr=[5,4,3,2,1];
//printing array before Sorting
console.log("array before sorting:",arr)
swapped_array=bubbleSort(arr);
//printing array after sorting
console.log("array after sorting:",swapped_array);