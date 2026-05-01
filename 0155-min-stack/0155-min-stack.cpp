class MinStack {
public:
    stack<long long>st;
    long long mini=LLONG_MAX;
    // typedef long long  LL;
    MinStack() {
        
    }
    
    void push(int val) {
        long long v=val;
        if(st.empty())
        {
            mini=v;
            st.push(v);
        }
        else{        
            if(v>=mini)
                //no need to updte mini,insert el the way it is
                st.push(v);
            else{         //means val is < mini
                st.push(2*v-mini);  // this will always be less than val
                //update mini 
                mini=v;              //update mini

            }
        }
    }
    
    void pop() {
        long long m=st.top();
        st.pop();
        //if the popped el was not the real el(m<mini)  update mini
        if(m<mini)
            mini=2*mini-m;      //from the formula(2*val-mini=newval)
        
    }
    
    int top() {
        long long m = st.top();
        if(m<mini)        //mini is the real elemnt
        {
            return mini;  
        } 
        return m;            //m is the real el (m>=mini)   
    }
    
    int getMin() {
        return (int)mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */