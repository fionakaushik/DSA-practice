class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort descending by the difference (minimum - actual)
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int total_energy = 0;
        int current_energy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (current_energy < minimum) {
                total_energy += (minimum - current_energy);
                current_energy = minimum;
            }
            current_energy -= actual;
        }

        return total_energy;
        
    }
};