class Solution {
public:
    string processStr(string s) {
        string res="";
        for (char ch : s)
        {
            if(ch=='*')
            {
                if(res.length()!=0)
                    res.pop_back(); //or res.resize(res.length()-1)

            }
            else if(ch=='#')
            {
                res+=res;
            }
            else if(ch=='%')
            {
                reverse(res.begin(),res.end());
            }
            else
                res+=ch;
        }
        return res;
        
    }
};