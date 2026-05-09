class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>st; //list also has lifo principal(as stack) and we won't need tp reverse while outputting
        for( int i=0;i<n;i++)
        {
            if(asteroids[i]>0) //insert in the list +ve elemnt
                st.push_back(asteroids[i]);
            else                  //if neg el
            {
                while(!st.empty() && st.back()>0 &&st.back()<abs(asteroids[i]))
                    st.pop_back();
                if(!st.empty() && st.back()>abs(asteroids[i]))  //not necessary to write 
                    continue;
                if(!st.empty() && st.back()==abs(asteroids[i]))
                    st.pop_back();
                else if(st.empty()  || st.back()<0)
                    st.push_back(asteroids[i]);


            }

        }
        return st;
        
    }
};