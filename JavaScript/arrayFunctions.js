function arrayIntersection(array1, array2) {
  return array1.filter((x) => array2.includes(x));
}

/*
/ array1 : The array to compare from
/ array2 : The array to compare against 
/ Return : All values from array1 wich not exist in array2
*/
function arrayDifference(array1, array2) {
  return array1.filter((x) => !array2.includes(x));
}

/*
/ array1 : The array to compare from
/ array2 : The array to compare from 
/ Return : All different values from array1 and array2
*/
function arraySymetricDifference(array1, array2) {
  return array1
    .filter((x) => !array2.includes(x))
    .concat(array2.filter((x) => !array1.includes(x)));
}

// Examples

let array1 = [1, 2, 3, 4];
let array2 = [0, 2, 7, 4];

console.log(arrayIntersection(array1, array2));
console.log(arrayDifference(array1, array2));
console.log(arraySymetricDifference(array1, array2));
