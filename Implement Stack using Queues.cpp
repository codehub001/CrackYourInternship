class MyStack {
    queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x = q1.back();
        int siz = q1.size();
        for(int i = 0; i < siz-1; i++){
            q1.push(q1.front());
            q1.pop();
        }
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
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
