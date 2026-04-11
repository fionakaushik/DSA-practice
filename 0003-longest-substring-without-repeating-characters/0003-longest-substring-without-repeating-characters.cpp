class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int>v(256,-1);//stores current idx of character we're at 
        int maxlen=0;

        int l=0,r=0;
        while(r<s.size())
        {
            if(v[s[r]]!=-1)//v[automatically converts to int],means we find in v that char's idx
            {
                if(v[s[r]]>=l)  //the current substr(from l to r)
                {
                    l=v[s[r]]+1;
                }


            }
            int len = r-l+1;
            maxlen=max(len,maxlen);

            //insert in v with the curr idx 
            v[s[r]]=r;
            r++;

        }
        return maxlen;

        
    
    }
};