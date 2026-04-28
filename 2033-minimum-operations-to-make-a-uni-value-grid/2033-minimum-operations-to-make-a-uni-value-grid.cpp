class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<int>arr;                             //SC: O(M*N)

        //step 1: flatten the grid
        for(int i=0;i<m;i++)                        //TC : O(M*N)
            for(int j=0;j<n;j++)
                arr.push_back(grid[i][j]);

        //step 2:sort the arr
        int l=arr.size();
        // sort(arr.begin(),arr.end());                //T.C:O(M*N LOG M*N)

        nth_element(arr.begin(),arr.begin()+l/2,arr.end()); //sorts l/2th el in avg of o(l) time 
        
        //find the median/mid elemnt of array ;
        
        int idx=floor(l/2);  //mid idx 

        int target =arr[idx];    //mid val
        int cnt=0;

        for(auto &num:arr)                             //O(M*N)
        
        {
            if(target% x!=num%x)   //all nums in the array should hve same remainders then only valid grid
                return -1;
            
            cnt+=abs(target-num)/x;  //no of operations 

        }
        return cnt;


        
        
        
    }
};