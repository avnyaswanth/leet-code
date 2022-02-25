class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        
        q1.push(x);
        while(!q2.empty())
        {
            int ele = q2.front();
            q2.pop();
            q1.push(ele);
        }
        swap(q1, q2);
        
    }
    
    int pop() {
        int ans = 0;
        ans = q2.front();
        q2.pop();
        return ans;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
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