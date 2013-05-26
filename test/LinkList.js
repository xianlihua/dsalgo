describe('LinkList', function () {

    describe('#init', function () {
        var list = new LinkList();

        it('初始化的 LinkList 对象，应该为空列表', function () {
            assert(list.length === 0);
            assert(list.head === null);
        });

        it('长度为 0 的列表对象，其 isEmpty() 方法应该返回 true', function () {
            assert(list.isEmpty() === true);
        });
    });

    describe('#constructor', function () {
        var list = new LinkList();
        it('LinkList 的实例的构造函数应该为 LinkList', function () {
            assert(list.constructor === LinkList);
        });
    });

    describe('#insert(), #get(), #remove(), #clear()', function () {
        var list = new LinkList();
        list.insert(0, 'www');
        list.insert(1, '.');
        list.insert(2, 'csser');
        list.insert(3, '.');
        list.insert(4, 'com');

        it('insert() 方法应该能向列表中正常插入数据', function () {
            assert(list.get(0) === 'www');
            assert(list.get(2) === 'csser');
            assert(list.get(4) === 'com');
        });

        it('get() 方法应该能正确返回列表指定索引的数据', function () {
            assert(list.get(2) === 'csser');
            assert(list.get(-1) === null);
            assert(list.get(100) === null);
        });

        it('remove() 方法应该能移除列表指定索引处的值，并改变列表的长度', function () {
            list.remove(3);
            list.remove(1);
            assert(list.length === 3);
            assert(list.get(1) === 'csser');
        });

        it('clear() 之后列表应该变为空列表', function () {
            list.clear();
            assert(list.length === 0);
            assert(list.get(0) === null);
            assert(list.head === null);
        });
    });

    describe('#push(), #unshift()', function () {
        it('push() 方法可以正确的向列表尾部插入数据', function () {
            var list = new LinkList();
            list.push('hello');
            list.push('CSSer!');

            assert(list.length === 2);
            assert(list.get(0) === 'hello');
            assert(list.get(2) === null);
        });

        it('unshift() 方法可以正确的向列表头部插入数据', function () {
            var list = new LinkList();
            list.unshift('CSSer!');
            list.unshift('hello');

            assert(list.length === 2);
            assert(list.get(0) === 'hello');
            assert(list.get(-1) === null);
            assert(list.get(2) === null);
        });
    });

    describe('#toArray()', function () {
        it('toArray() 方法可以将单链表转换为数组', function () {
            var list = new LinkList();
            list.push('hello');
            list.push(' CSSer!');

            var array = list.toArray();

            assert(array.length === 2);
            assert(array[0] === 'hello');
            assert(array.join('') === 'hello CSSer!');
        });
    });

});