class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for (const string& q : queries) {
            for (const string& d : dictionary) {
                int edits = 0;
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) edits++;
                    if (edits > 2) break; // Optimization
                }
                
                if (edits <= 2) {
                    ans.push_back(q);
                    break; // Match found, move to next query
                }
            }
        }
        return ans;
        
        
    }
};