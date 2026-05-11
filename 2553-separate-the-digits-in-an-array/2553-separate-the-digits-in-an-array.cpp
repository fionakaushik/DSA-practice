class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        //approach 1: string 
        // vector<int>res;
        // for( int n : nums)
        // {
        //     string s= to_string(n);
        //     for(char c: s)
        //         res.push_back(c-'0') ; // Convert char '1' to int 1
        // }
        // return res;
        
        //approach 2: mathematcal approach
        //extract the digits into a temporary vector, reverse them, and then add them to your result.
        vector<int>res;
        for( int n :nums)  //for each no.in array create a temp vector 
        {
            vector<int>temp;
            while(n>0)
            {
                temp.push_back(n%10);
                n=n/10;
            }
            // Add them to the final result in the correct order
            for( int i=temp.size()-1;i>=0;i--)  //loop from backward of temp
            {
                res.push_back(temp[i]);
            }
        }
        return res;
        
        
    }
};