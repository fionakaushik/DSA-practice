class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        //CORRECT SOLUTION
        // {Result} = |{Count of R}) - (Count of L})| + {Count of _)
        int countL = 0, countR = 0, count_ = 0;
        for (char c : moves) {
            if (c == 'L') countL++;
            else if (c == 'R') countR++;
            else count_++;
        }
        return abs(countL - countR) + count_;


        
    }
};