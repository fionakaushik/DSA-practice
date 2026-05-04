class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =nums.size();
        vector<int>res(n,-1);
        stack<int>st;
        
        //for nge(nxt _greater_ el) we start iterating from back of hypotheicl double array
        for(int i= 2*n-1 ;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();
            if( i<n)
            {
                res[i]=st.empty()?-1:st.top();   //trying to access res[i] means res should be initialized w a size while initializn
            }
            st.push(nums[i%n]);
        }
        return res;
        
    }
};