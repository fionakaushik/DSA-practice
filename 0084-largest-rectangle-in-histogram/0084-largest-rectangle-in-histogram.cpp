class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //optimal would be finding out nse(nxt smaller el idx) & pse( prev smaller el ) for each idx i and calculating area of each i using the formula : arr[i]* (nse[i]-pse[i]-1) ,TC:O(5N)

        //Optimal would be usning monotonic increasing stack ,so as a smaller el is encoutered we know it's nse for st.top el and pse would be just below st.top   T.C: O(N) SINGLE PASS solution

        stack<int>st;
        int maxArea=0;
        for( int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                int nse=i;    //idx of nse for st.top() el 
                int el=heights[st.top()];                                 //height
                st.pop();     //pop the top el to get pse for st.top()
                int pse=st.empty()?-1:st.top();    //idx of prev small el 

                maxArea=max(maxArea,el*(nse-pse-1));                   //height * width
                
            }
            st.push(i);   //greater or equal idx el
        }
        //for remaining elemnts that means for those we dint find nse
        while(!st.empty())
        {
            int nse=heights.size();  // hypothtical idx n
            int el = heights[st.top()];
            st.pop();
            int pse=st.empty()?-1:st.top();

            maxArea=max( maxArea,el*(nse-pse-1));
        }

        return maxArea;

        
    }
};