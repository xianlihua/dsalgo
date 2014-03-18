// 选择排序
function select (array) {
    if (array.length <= 1) {
        return array;
    }

    var i, j, pos, tmp, len = array.length;
    for (i = 0; i < len - 1; i++) {
        pos = i;
        for (j = i + 1; j < len; j++) {
            if (array[j] < array[pos]) {
                pos = j;
            }
        }
        if (pos > i) {
            tmp = array[i];
            array[i] = array[pos];
            array[pos] = tmp;
        }
    }
    return array;
}

console.log(select('46,79,56,38,40,84'.split(',')));