class MyQueue {
private :
    stack<int>s1,s2;
public:
    MyQueue() {
        
    }
    //o(2n) operation
    void push(int x) {
        if(s1.size()==0)
            s1.push(x);
        else
        {
            // 1. Move all elements to s2
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();

            }
            // 2. Put the new element at the bottom of the "queue"
            s1.push(x);

            // 3. Move everything back to s1
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
                
            }
            

        }
    }
    //o(1) oper
    int pop() {
        int front_el=s1.top();
        s1.pop();
        return front_el;
        
    }
    
    int peek() {
        return s1.top();  //the first oldest el enterd
    }
    
    bool empty() {
        return s1.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */