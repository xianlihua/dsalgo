describe('Stack', function () {
    describe('#init', function () {
        it('初始化的栈应该为空栈', function () {
            var stack = new Stack();

            assert(stack.length === 0);
            assert(stack.top === -1);
            assert(typeof stack.data === 'object');
        });
    });

    describe('#push(), #pop()', function () {
        var stack = new Stack();
        stack.push('hello');
        stack.push('csser!');

        it('push() 方法应该能正确的向栈顶添加数据', function () {
            assert(stack.length === 2);
            assert(stack.top === 1);
            assert(stack.getTop() === 'csser!');
            assert(stack.data.join(' ') === 'hello csser!');
        });

        it('pop() 方法应该能正确的从栈顶移除数据', function () {
            assert(stack.pop() === 'csser!');
            assert(stack.length === 1);
            assert(stack.top === 0);
            assert(stack.data.join('') === 'hello');
            assert(stack.isEmpty() === false);
        });
    });

    describe('#clear, #isEmpty', function () {
        it('clear() 方法应该能正确清除栈使之变成空栈', function () {
            var stack = new Stack();
            stack.push('hello');
            stack.push('csser!');

            stack.clear();
            assert(stack.length === 0);
            assert(stack.top === -1);
            assert(stack.data.length === 0);
            assert(stack.isEmpty() === true);
        });
    })
});