/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
    queue<int> q;
    queue<int> q2;

    queue<int>* stack;
    queue<int>* e;

    void move(queue<int>& first, queue<int>& second) {
        while (!first.empty()) {
            second.push(first.front());
            first.pop();
        }
    }

    void swap() {
        auto temp = stack;
        stack = e;
        e = temp;
    }

public:
    MyStack() {
        stack = &q;
        e = &q2;
    }

    void push(int x) {
        e->push(x);
        move(*stack, *e);
        swap();
    }

    int pop() {
        int n = stack->front();
        stack->pop();
        return n;
    }

    int top() {
        return stack->front();
    }

    bool empty() {
        return stack->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
