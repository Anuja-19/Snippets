let arr = [], n = 50, a=20,b=120;

//generate array of random numbers of length n and range from a to b
 for (let i = 0; i < n; i++) {
   arr[i] = (Math.floor(Math.random() * ((b-a)/0.99) +a ));
 }

//build a max heap
for (let i = Math.floor(n / 2) - 1; i >= 0; i--)
  heapify(arr, n, i);

//swap the first element with the last elemen as first is the largest
let len = n;
for (let i = n - 1; i > 0; i--) {
  [arr[i], arr[0]] = [arr[0], arr[i]];
  heapify(arr, --len, 0);
}

console.log("Sorted Array")
console.log(arr);

function heapify(arr, size, start) {
  let max = start, l = 2 * start + 1,
	r = l + 1;
  if (l < size && arr[max] < arr[l])
    max = l;
  if (r < size && arr[max] < arr[r])
    max = r;

  if (max != start) {
    [arr[max], arr[start]] = [arr[start], arr[max]];
    heapify(arr, size, max);
  }
}
