class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for( int i=0;i<n;i++)
        {
            while( !st.empty() && k>0 && (st.top()-'0')>(num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);

        }
        //edge case 2 when s="123456"no nxt el is smaller than prev ,so no k--; k remains as is,, all el pushed in stack from prev loop,remove last k el then
        while(k>0)
        {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";

        //preparing the resultant string 
        string res="";
        while(!st.empty())
        {
            // res+=st.top();
            // st.pop();
            res.push_back(st.top());
            st.pop();
        }
        //handling trailing zeros which turn to leading zeros after reverse o string res
        while(res.size()!=0 && res.back() =='0')
        {
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        //what if all elmnt in res were 0 and got popped
        if(res.empty()) return "0";
        return res;

        

    }
};