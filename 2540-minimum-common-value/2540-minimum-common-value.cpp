class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int l=0;
        int r=0;
        while(l<m && r<n)
        {
            if (nums1[m-1] < nums2[0] || nums2[n-1] < nums1[0]) return -1;
            
            if(nums1[l]==nums2[r])
                return nums1[l];
            else if(nums1[l]<nums2[r])
                l++;
            else
                r++;
        }
        return -1;
        
    }
};