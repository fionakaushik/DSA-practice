class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0) ;
        // Pass 1: Count the frequency of each character
        for( char ch: s){
            freq[ch-'a']++;
        }

        //Pass 2: Find the first character with a frequency of 1
        for( int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a']==1)
                return i; //// Return its index immediately
        }
        return -1;

    }
};