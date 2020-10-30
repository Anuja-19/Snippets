function jumpSearch(arr, x, n) {
    // Finding block size to be jumped
    let step = Math.sqrt(n);

    // Finding the block where element is present
    let prev = 0;
    while (arr[Math.min(step, n) - 1] < x) {
        prev = step;
        step += Math.sqrt(n);
        if (prev >= n) {
            return -1;
        } 
    }

    // Doing a linear search for x in 
    // block beginning with prev

    while (arr[prev] < x) {
        prev += 1;
        if (prev == Math.min(step, n)) {
            return -1;
        }
    }

    if (arr[prev] == x) {
        return prev;
    }
    return -1;
}

let arr = [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 ];
let x = 55;
let n = arr.length;

let index = jumpSearch(arr, x, n);
console.log(`Number ${x} is at index ${index}`);