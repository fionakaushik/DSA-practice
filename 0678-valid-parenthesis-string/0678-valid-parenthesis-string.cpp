class Solution {
public:
    bool checkValidString(string s) {
        int minOpen=0,maxOpen=0;
        for( char ch: s)
        {
            if( ch=='(') //opening
            {
                minOpen++;
                maxOpen++;

            }
            else if(ch==')') //closing
            {
                minOpen--;
                maxOpen--;
            }
            else if( ch=='*')
            {
                minOpen--; //consider it closing braces )
                maxOpen++;  //consider it opening ( braces
            }
            if(maxOpen<0) return false; //closing more than open
            if(minOpen<0) minOpen=0; //reset minopen to 0


        }
        return (minOpen==0);
        
    }
};