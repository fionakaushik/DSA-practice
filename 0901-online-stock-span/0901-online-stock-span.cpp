class StockSpanner {
public:
    //prev greater el is found at idx j then (i-j)is thr cnt of days whose price<=current day price
    stack<pair<int,int>>st;     //{idx,val}
    int idx=-1;

    StockSpanner() {
        //so wehn conctructor is called fresh start 
        idx=-1;
        
    }
    
    int next(int price) {
        idx=idx+1; 
        while(!st.empty()&& st.top().second<=price)  //pge idx is to be found
            st.pop();
        //pge found
        int ans=idx-(st.empty()?-1:st.top().first ); //ans should be evaluated before pushing new idx and val in stak
        st.push({idx,price});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */