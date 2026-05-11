class Solution {
private:
    int lHist(vector<int>&arr)
    {
        int maxArea=0;
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                int ht=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int area=ht*(nse-pse-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        //remaining el in stack that could not have nse
        while(!st.empty())
        {
            int ht=arr[st.top()];
            st.pop();
            int nse=arr.size();
            int pse=st.empty()?-1:st.top();
            int area=ht*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //pre-requesite:largest rectangle sum
        //construct each wors as histograms using prefixSum nd send each row to largest_rectangleSum fn() 

        //constructing prefixSum array(2*d)
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>p_sum(rows,vector<int>(cols,0));
        //column:
        for(int j=0;j<matrix[0].size();j++)
        {
            int sum=0;
            //...row
            for( int i=0;i<matrix.size();i++)
            {
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') 
                    sum=0;    //reset to 0
                p_sum[i][j]=sum;
            }
        }
        int globalMaxArea=0;
        //now send each row to largest_rect_area fn()
        for(int i=0;i<matrix.size();i++)
        {
            globalMaxArea=max(globalMaxArea,lHist(p_sum[i]));
           
        } 
        return globalMaxArea;
    }
};