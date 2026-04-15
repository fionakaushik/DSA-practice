class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxfreq=0;
        int maxlen=INT_MIN;

        vector<int>freq(26,0);
        while(r<s.length())
        {
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            if(((r-l+1)-maxfreq)<=k)
            {
                maxlen=max(maxlen,(r-l+1));

            }
            else
            {
                freq[s[l]-'A']--;
                l++;
                maxfreq=0;
            }
            r++;

        }
        return maxlen;

        
    }
};