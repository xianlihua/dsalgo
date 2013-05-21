/**
 * 顺序线性表的 Javascript 实现
 */
function ArrayList () {
    this.length = 0;
    this.data = [];
}

ArrayList.prototype = {
    'constructor': ArrayList,

    /**
     * 判断列表是否为空
     * @return {Boolean} 列表为空返回 true，否则返回 false
     */
    'isEmpty': function () {
        return this.length === 0;
    },

    /**
     * 清空列表
     */
    'clear': function () {
        this.data = [];
        this.length = 0;
    },

    /**
     * 获取列表指定索引的值
     * @param  {Number} index 指定的索引位置
     * @return {Mixed}       index 位置的值
     */
    'get': function (index) {
        return this.data[index];
    },

    /**
     * 查找指定值在列表中的索引位置
     * @param  {Mixed} value 要查找的值
     * @return {Number}       如果值在列表中存在，返回其在列表中的索引，否则返回 -1
     */
    'indexOf': function (value) {
        for (var i = 0; i < this.length; i++) {
            if (value === this.data[i]) return i;
        }

        return -1;
    },

    /**
     * 向列表中追加值
     * @param  {Mixed} value 要追加的值
     */
    'append': function (value) {
        this.data.push(value);
        this.length++;
    },

    /**
     * 向列表中插入数据
     * @param  {Number} index 数据要插入的位置
     * @param  {Mixed} value 要插入的值
     */
    'insert': function (index, value) {
        if (index < 0 || index > this.length) {
            throw 'Error: insert error';
        }

        var i = this.length;
        while (i > index) {
            this.data[i] = this.data[i - 1];
            i--;
        }

        this.data[index] = value;
        this.length++;
    },

    /**
     * 移除列表中指定位置的值
     * @param  {Number} index 要移除值所在的位置
     * @return {Mixed}       移除的值
     */
    'remove': function (index) {
        if (this.length === 0 || index < 0 || index > this.length - 1) {
            throw 'Error: remove error';
        }

        var result = this.data[index];
        var i = index;
        while (i < this.length) {
            this.data[i] = this.data[i + 1];
            i++;
        }

        this.length--;
        return result;
    }
};

// test
var list = new ArrayList();
list.insert(0, 'www'); // ['www']
list.append('csser'); // ['www', 'csser']
list.insert(2, 'com'); // ['www', 'csser', 'com']
console.log(list.data.join('.')); // www.csser.com

list.insert(0, 'http://');
list.insert(2, '.');
list.insert(4, '.');
console.log(list.data.join('')); // http://www.csser.com

console.log(list.remove(0)); // http://
console.log(list.data.join('')); // www.csser.com

console.log(list.length); // 5
console.log(list.isEmpty()); // false

list.clear();
console.log(list.isEmpty()); // true