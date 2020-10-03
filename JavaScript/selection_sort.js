let selectionSort = (arr) => {
    let length = arr.length;
    for (let i = 0; i < length; i++) {
        let min = i;
        for (let j = i + 1; j < length; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min !== i) {
            // Swapping the elements
            let tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    return arr;
}

let arr = [10,12,9,25,3];
selectionSort(arr);
console.log(arr);

// Output: [3, 9, 10, 12, 25]