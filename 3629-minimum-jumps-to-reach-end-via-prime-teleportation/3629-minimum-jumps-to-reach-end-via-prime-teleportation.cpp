class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);

        // 1. Sieve to find primes and smallest prime factors
        vector<int> spf(max_val + 1);
        vector<bool> is_prime(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        for (int i = 2; i <= max_val; ++i) {
            if (is_prime[i]) {
                for (int j = 2 * i; j <= max_val; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // 2. Map primes to indices of their multiples
        // Optimization: Only map primes that actually appear in the array
        unordered_map<int, vector<int>> prime_to_multiples;
        
        // Find all primes up to max_val to build the buckets
        vector<int> all_primes;
        for(int i = 2; i <= max_val; ++i) if(is_prime[i]) all_primes.push_back(i);

        for (int p : all_primes) {
            for (int multiple = p; multiple <= max_val; multiple += p) {
                // This part is slow if done naively. 
                // Better: Iterate through nums and for each nums[j], 
                // find its prime factors and add j to those prime buckets.
            }
        }
        
        // Revised Mapping: Efficiently fill buckets
        unordered_map<int, vector<int>> buckets;
        for(int i = 0; i < n; ++i) {
            int val = nums[i];
            for(int d = 2; d * d <= val; ++d) {
                if(val % d == 0) {
                    if(is_prime[d]) buckets[d].push_back(i);
                    if(is_prime[val/d]) buckets[val/d].push_back(i);
                }
            }
            if(is_prime[val]) buckets[val].push_back(i);
        }

        // 3. BFS
        queue<int> q;
        q.push(0);
        vector<int> dist(n, -1);
        dist[0] = 0;
        vector<bool> visited_prime(max_val + 1, false);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) return dist[u];

            // Adjacent Steps
            for (int v : {u - 1, u + 1}) {
                if (v >= 0 && v < n && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }

            // Prime Teleportation: ONLY if nums[u] is prime
            int p = nums[u];
            if (p <= max_val && is_prime[p] && !visited_prime[p]) {
                for (int v : buckets[p]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                visited_prime[p] = true; // Use each prime bucket only once
            }
        }

        return -1;
    }
};