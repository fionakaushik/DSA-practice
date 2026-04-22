class Solution {
public:
    string minWindow(string s, string t) {
        int m =s.size();
        int n =t.size();
        //a loop for storing char of t in a map
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[t[i]]++;
        }

        int cnt=0;
        int startIdx=-1;
        int minlen=INT_MAX;
        int l=0,r=0; //sliding wind +2 ptr approach
        while(r<m)
        {
            if(mp[s[r]]>0) cnt++;
            //not found then insert in map w neg freq
            mp[s[r]]--;

            while(cnt==n)   //keep shrinking long as cnt = t.size()
            {
                int len=r-l+1;
                if(minlen>len){
                    minlen=len;
                    startIdx=l;
                }
                //shrink
                mp[s[l]]++;     //(-1+1=0,0+1=1)
                if(mp[s[l]]>0)   //means freq of an el of t str has returned back to og freq ,which means an elemnt of t has been removed , hence cnt--;
                {
                    cnt=cnt-1;

                }
                l++;

            }
            r++;



           
        }
        return(startIdx==-1?"":s.substr(startIdx,minlen));

    }
};