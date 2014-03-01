/**
 * 单链表的 Javascript 实现
 */
function LinkList () {
    this.length = 0;
    this.head = null;
}

LinkList.prototype = {
    'constructor': LinkList,

    /**
     * 生成结点
     * @param  {Mixed} data 节点数据
     * @return {Node}      结点对象
     */
    'makeNode': function (data) {
        return {
            data: data,
            next: null
        };
    },

    /**
     * 判断链表是否为空
     * @return {Boolean} 链表是否为空的布尔值
     */
    'isEmpty': function () {
        return this.length === 0;
    },

    /**
     * 清空链表
     */
    'clear': function () {
        var current = this.head;
        var tmp;
        while (current) {
            tmp = current.next;
            current.next = null;
            current = tmp;
        }
        this.head = null;
        this.length = 0;
    },

    /**
     * 获取链表指定索引处的值
     * @param  {Number} index 索引
     * @return {Mixed}       index 索引处的值
     */
    'get': function (index) {
        if (index < 0 || index > this.length) return null;
        var current = this.head;
        var i = 0;
        while (current && i < index) {
            current = current.next;
            ++i;
        }

        if (!current) return null;

        return current.data;
    },

    /**
     * 向链表末尾追加数据
     * @param  {Mixed} data 要追加的数据
     */
    'push': function (data) {
        this.insert(this.length, data);
    },

    /**
     * 向链表头部增加数据
     * @param  {Mixed} data 要追加的数据
     */
    'unshift': function (data) {
        this.insert(0, data);
    },

    /**
     * 向链表中指定索引位置插入数据
     * @param  {Number} index 插入位置
     * @param  {Mixed} data  插入的数据
     */
    'insert': function (index, data) {
        if (index < 0 || index > this.length) throw 'Error: insert index error';

        var node = this.makeNode(data);

        // 第一个结点
        if (this.head === null) {
            this.head = node;
            return ++this.length, undefined;
        }

        var current = this.head;
        var i = 0;

        // push
        if (index === this.length) {
            while(current.next) {
                current = current.next;
            }

            current.next = node;
            return ++this.length, undefined;
        }

        // unshift
        if (index === 0) {
            node.next = current;
            this.head = node;
            return ++this.length, undefined;
        }

        while (current && i < index) {
            current = current.next;
            i++;
        }

        if (!current || i > index) return;

        node.next = current.next;
        current.next = node;

        this.length++;
    },

    /**
     * 移出链表指定索引处的值
     * @param  {Number} index 指定的索引
     * @return {Mixed}       被移除结点包含的数据
     */
    'remove': function (index) {
        var prev = this.head;

        if (index === 0) {
            this.head = prev.next;
            return;
        }

        var i = 0;
        while (prev && i < index - 1) {
            prev = prev.next;
            i++;
        }

        if (!prev || i > index) return null;

        var current = prev.next;
        prev.next = current.next;

        return --this.length, current;
    },

    /**
     * 将链表转换为顺序表
     * @return {Array} 链表的顺序表形式
     */
    'toArray': function () {
        var current = this.head;
        var array = [];

        while (current) {
            array.push(current.data);
            current = current.next;
        }

        return array;
    }
};