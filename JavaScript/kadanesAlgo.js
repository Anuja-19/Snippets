var maximumSubArray = function(array) {
    var ans = array[0];
    var sum = array[0];


    for (var i = 1; i < array.length; i++) {

        ans = Math.max(array[i], ans + array[i]);
        sum = Math.max(sum, ans);
    };
    return sum;

};
maximumSubArray([-10, -11, -12]);//-10
