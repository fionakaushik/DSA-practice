class Solution {
private:
    vector<int>get_next_greater_left(vector<int>arr,int n)
    {
        vector<int> res(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            res[i]=st.empty()?-1:st.top();
            
            st.push(i);
        }
        return res;
    }
private:
    vector<int>get_next_greater_right(vector<int>arr,int n)
    {
        vector<int> res(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            res[i]=st.empty()?n:st.top();
            
            st.push(i);
        }
        return res;
    }
private:
    long long sumOfSubarrayMaximums(vector<int>arr)
    { 
        long long maxsum=0; 
        int n=arr.size(); 
        vector<int>ngl=get_next_greater_left(arr,n); //next greater left(idx at which next greater el is found)
        vector<int>ngr=get_next_greater_right(arr,n); //next greater right(idx at which next greater el is found)
        for( int i=0;i<arr.size();i++)
        {
            int left=i-ngl[i];
            int right=ngr[i]-i;
            
            //subarrays(no of subarrays where the given el at i is max)
            long long subarrays=left* right;
            //contribution of these in sum
            long long contribution=subarrays*arr[i];
            maxsum+=contribution;
        }
        return maxsum;
    }
private:
    vector<int>get_next_smaller_left(vector<int>arr,int n)
    {
        vector<int> res(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            res[i]=st.empty()?-1:st.top();
            
            st.push(i);
        }
        return res;
    }
private:
    vector<int>get_next_smaller_right(vector<int>arr,int n)
    {
        vector<int> res(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            res[i]=st.empty()?n:st.top();
            
            st.push(i);
        }
        return res;
    }


private:
    long long sumOfSubarrayMinimums(vector<int>arr)
    { 
        long long minsum=0; 
        int n=arr.size(); 
        vector<int>nsl=get_next_smaller_left(arr,n); //next smaller left(idx at which next smaller el is found)
        vector<int>nsr=get_next_smaller_right(arr,n); //next smaller right(idx at which next smaller el is found)
        for( int i=0;i<arr.size();i++)
        {
            int left=i-nsl[i];
            int right=nsr[i]-i;
            
            //subarrays(no of subarrays where the given el at i is max)
            long long subarrays=left* right;
            //contribution of these in sum
            long long contribution=subarrays*arr[i];
            minsum+=contribution;
        }
        return minsum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        //O(n^2) complexity -brute
        //optimal -> sum of aubarray maximums- sum of subarray minimums
        long long ranges_sum=sumOfSubarrayMaximums(nums)-sumOfSubarrayMinimums(nums);

        return ranges_sum;
        
    }
};