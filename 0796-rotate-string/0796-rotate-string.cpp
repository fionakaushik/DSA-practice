class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.length();
        int n=goal.length();
        if(n!=m) return false;
         
        if((s+s).find(goal)!=string::npos)
            return true;
        return false;

        
    }
};