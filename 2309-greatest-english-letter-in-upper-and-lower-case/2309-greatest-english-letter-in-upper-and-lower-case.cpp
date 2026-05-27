class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        string ans = "";
        // Mark the presence of each character
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        for( int i=25;i>=0;i--)
        {
            if(lower[i]&&upper[i])
            // Convert the index back to the uppercase character string
                return string(1,'A'+i); //creates a string of length 1 containing the character matching the ASCII value of 'A' + i

                //or we could write this
                // ans+=('A'+i)
                //return ans
        }
        return "";
    }
};