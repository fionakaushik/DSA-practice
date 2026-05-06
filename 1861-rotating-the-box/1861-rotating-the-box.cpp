class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply Gravity (move stones to the right)
        for (int i = 0; i < m; i++) {
            int empty = n - 1; // The rightmost available spot
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    // Move stone to the 'empty' spot and mark current as empty
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty] = '#';
                    empty--;
                } else if (boxGrid[i][j] == '*') {
                    // Obstacle blocks further movement; reset 'empty' pointer
                    empty = j - 1;
                } else if (boxGrid[i][j] == '.') {
                    // Cell is already empty; 'empty' pointer stays where it is
                }
            }
        }

        // Step 2: Rotate the Box 90 Degrees Clockwise
        // New dimensions: n x m
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBox;
        
    }
};