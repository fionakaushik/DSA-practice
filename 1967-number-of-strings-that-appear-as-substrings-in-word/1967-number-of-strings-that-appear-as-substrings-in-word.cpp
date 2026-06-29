class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        //string::npos is a special constant value that represents "not found" or "no position."
        //returned by word.find()—when the substring or character you are searching for cannot be located inside the string.
        int count=0;
        for( const string& p: patterns)
        {
            // Find if pattern 'p' exists inside 'word'
            if(word.find(p)!=string::npos) //means we found p in word
                count++;

        }
        return count;
    }
};