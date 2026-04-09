class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorval=0;
        for(int num:nums)
            xorval=xorval^num;
        return xorval;
        
    }
};