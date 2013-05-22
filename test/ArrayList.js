describe('ArrayList', function () {

    describe('#init', function () {
        var list = new ArrayList();

        it('初始化的 ArrayList 对象，应该为空列表', function () {
            assert(list.length === 0);
            assert(list.data.length === 0);
        });

        it('长度为 0 的列表对象，其 isEmpty() 方法应该返回 true', function () {
            assert(list.isEmpty() === true);
        });
    });

    describe('#constructor', function () {
        var list = new ArrayList();
        it('ArrayList 的实例的构造函数应该为 ArrayList', function () {
            assert(list.constructor === ArrayList);
        });
    });

    describe('#insert(), #get(), #remove(), #clear()', function () {
        var list = new ArrayList();
        list.insert(0, 'www');
        list.insert(1, '.');
        list.insert(2, 'csser');
        list.insert(3, '.');
        list.insert(4, 'com');

        it('insert() 方法应该能向列表中正常插入数据', function () {
            assert(list.data[0] === 'www');
            assert(list.data[2] === 'csser');
            assert(list.data[4] === 'com');
            assert(list.data.join('') === 'www.csser.com');
        });

        it('get() 方法应该能正确返回列表指定索引的数据', function () {
            assert(list.get(2) === 'csser');
            assert(list.get(-1) === undefined);
            assert(list.get(100) === undefined);
        });

        it('remove() 方法应该能移除列表指定索引处的值，并改变列表的长度', function () {
            list.remove(3);
            list.remove(1);
            assert(list.length === 3);
            assert(list.data[1] === 'csser');
            assert(list.data.join('.') === 'www.csser.com');
        });

        it('clear() 之后列表应该变为空列表', function () {
            list.clear();
            assert(list.length === 0);
            assert(list.data[0] === undefined);
        });
    });

});