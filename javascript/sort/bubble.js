// 冒泡排序
function bubble (array) {
    var i, j, tmp, len = array.length;
    for (i = 1; i < len; i++) {
        for (j = 0; j < len - i; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    return array;
}

console.log(bubble('46,79,56,38,40,84'.split(',')));