class MyStack {
public:
    //using single queue;
    queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
        int sz=q.size();       
        q.push(x);
        while(sz)       //o(n),we amke sure last pushed el becomes front of queue
        {
            q.push(q.front());
            q.pop();
            sz--;
        }
        
    }
    
    int pop() {
        int front_el=q.front();//q.front()
        q.pop();
        return front_el;
    }
    
    int top() {
        
        return q.front();
    }
    
    bool empty() {
        // int sz=q.size();
        // return sz==0?true:false;  
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */