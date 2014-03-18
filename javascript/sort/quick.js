// TODO:
function quick (array) {
    if (array.length === 2) {
        return array;
    }

    var left = [], right = [], tmp, mid = array[0];
    for (var i = 1, j = array.length - 1; i < j; i++, j--) {
        if (array[i] < mid) {
            left[left.length] = array[i];
        } else {
            right[right.length] = array[i];
        }
    }

    return quick(left).concat(mid, quick(right));
}

console.log(quick('46,79,56,38,40,84'.split(',')));