class Solution {
private: 
     vector<int>getNSL(vector<int> & arr,int n )
    {
        vector<int> res(n,-1);
        stack<int> st; //stack stores indices
        for( int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            res[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        return res;
    }
    vector<int>getNSR(vector<int> & arr,int n )
    {
        vector<int> res(n,-1);
        stack<int> st; //stack stores indices
        for( int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            res[i]=st.empty()?n:st.top();

            st.push(i);
        }
        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        //brute 
        // long long sum=0;
        // int mod =1e9+7;
        // for( int i=0;i<arr.size();i++)
        // {
        //     int mini =INT_MAX;
        //     for( int j =i;j<arr.size();j++)
        //     {
        //         mini=min(arr[j],mini);
        //         sum+=mini % mod;
        //     }
        // }
        
        // return sum;     //GIVES tLE( 9*10^8 is >10^8 hence TLE)

        //OPTIMAL USING MONOTONIC STACK 


   

        int n =arr.size();
        vector<int>NSL=getNSL(arr,n); //idx of nxt smaller el to left of/for each el in array
        vector<int>NSR=getNSR(arr,n); // idx of nxt asmaller el to right of/for each el in array

        long long tot_sum=0;
        int mod = 1e9+7;
        for( int i=0;i<n;i++)
        {
            long long left= i-NSL[i]; //idx i - idx at which nxt smaller el to i is found 
            long long right = NSR[i]-i;

            long long tot_subarrays=left*right; //subarrays having min =arr[i];
            long long sum= (arr[i]*tot_subarrays) % mod;

            tot_sum=(sum+tot_sum)%mod;


        }
        return (int)tot_sum;


    }
};