class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;  //monotonic decreasing stack

        //nge for elemnts in nums2
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums2[i])
                st.pop();
            mpp[nums2[i]]=st.empty()?-1:st.top();

            st.push(nums2[i]);
        }
        vector<int>ls;
        //look in map for nums1 elemnts 
        for( int i =0;i<nums1.size();i++)
        {
            ls.push_back(mpp[nums1[i]]);
        }

        return ls;
    }
};