class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // int n=colors.size();
        // int res=0;
        // //2 pass solution : fix colors[0] and keep moving i OR fix color[n-1] nd keep moving i 
        // int i=0;
        // while(colors[i]==colors[n-1] && i<n)  //color [n-1] fixed
        //     i++;
        // res=max(res,abs(i-(n-1)));

        // i=n-1;
        // while(colors[i]==colors[0] && i>=0)  //color [n-1] fixed
        //     i--;
        // res=max(res,abs(i-(n-1)));

        // return res;

        int n=colors.size();
        int res=0;
        //one pass solution 
        //take out dist of i from both color[0] & color [n-1] at the same time 
        for (int i =0;i<colors.size() ;i++)
        {
            if(colors[i]!=colors[0])
                res=max(res,i);
            
            if(colors[i]!=colors[n-1])
                res=max(res,abs(i-(n-1)));

        }
        return res;






        
    }
};