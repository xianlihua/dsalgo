/**
 * 顺序栈的 Javascript 实现
 */
function Stack () {
    this.length = 0;
    this.top = -1;
    this.data = [];
}

Stack.prototype = {
    'constructor': Stack,

    /**
     * 清空栈
     */
    'clear': function () {
        this.length = 0;
        this.top = -1;
        this.data = [];
    },

    /**
     * 判断栈是否为空栈
     * @return {Boolean} 如果为空栈，返回 true；否则返回 false
     */
    'isEmpty': function () {
        return this.length === 0 && this.top === -1;
    },

    /**
     * 获取栈顶数据
     * @return {Mixed} 栈顶数据
     */
    'getTop': function () {
        return this.top > -1 && this.data[this.top] || undefined;
    },

    /**
     * 数据进栈
     * @param  {Mixed} data 要添加的数据
     * @return {Number}      栈的长度
     */
    'push': function (data) {
        this.data[++this.top] = data;
        return ++this.length;
    },

    /**
     * 数据出栈
     * @return {Mixed} 出栈的数据
     */
    'pop': function () {
        if (this.top === -1) return;

        var data = this.data[this.top--];
        this.data.length--;
        return --this.length, data;
    }
};