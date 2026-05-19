class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        
        //sort both the arrays first
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<m && r<n)
        {
            if(g[l]<=s[r])
                l++;           //satisfied child ++;
            r++;                //cookies pointer always moves to next bigger cookie
        }
        return l;             //l stops at the next idx of no of child satified

        
    }
};