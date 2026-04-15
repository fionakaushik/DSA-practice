class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mini=INT_MAX;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                int st_dist=abs(i-startIndex);
                int cir_dist=min(n-st_dist,st_dist);

                mini=min(mini,cir_dist);
            }
        }
        return mini==INT_MAX?-1:mini;


        
    }
};