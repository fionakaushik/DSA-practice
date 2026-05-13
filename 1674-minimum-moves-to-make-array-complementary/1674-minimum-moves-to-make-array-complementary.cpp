class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // diff array to track changes in move counts for each possible sum X
        // Sums range from 2 to 2 * limit
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // Ensure a <= b for simplicity
            if (a > b) swap(a, b);

            // 1. Default: Assume 2 moves for all possible sums [2, 2 * limit]
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 2. Range for 1 move: [1 + a, limit + b]
            // We subtract 1 from the "2 moves" area to make it "1 move"
            diff[a + 1] -= 1;
            diff[limit + b + 1] += 1;

            // 3. The exact sum: a + b
            // We subtract another 1 from the "1 move" area to make it "0 moves"
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int min_moves = n; // Max possible moves is n
        int current_moves = 0;
        
        // Sweep through the difference array to find the minimum
        for (int sum = 2; sum <= 2 * limit; ++sum) {
            current_moves += diff[sum];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;

    }
};