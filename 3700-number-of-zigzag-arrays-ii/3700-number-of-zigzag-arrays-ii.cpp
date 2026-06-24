class Solution {
    long long MOD = 1e9 + 7;

        // Helper to multiply two matrices
        vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
            int sz = A.size();
            vector<vector<long long>> C(sz, vector<long long>(sz, 0));
            for (int i = 0; i < sz; ++i) {
                for (int k = 0; k < sz; ++k) {
                    if (A[i][k] == 0) continue;
                    for (int j = 0; j < sz; ++j) {
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return C;
        }

        // Helper for fast matrix exponentiation
        vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
            int sz = A.size();
            vector<vector<long long>> res(sz, vector<long long>(sz, 0));
            for (int i = 0; i < sz; ++i) res[i][i] = 1;
            while (p > 0) {
                if (p & 1) res = multiply(res, A);
                A = multiply(A, A);
                p >>= 1;
            }
            return res;
        }
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;
        if (n == 2) return (1LL * m * (m - 1)) % MOD;

        int sz = 2 * m;
        // T[i][j] represents transition from state i to state j
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        // 0 to m-1: next_down states
        // m to 2m-1: next_up states
        for (int x = 0; x < m; ++x) {
            // From (x, next_down) to (y, next_up) where y < x
            for (int y = 0; y < x; ++y) {
                T[x][m + y] = 1;
            }
            // From (x, next_up) to (y, next_down) where y > x
            for (int y = x + 1; y < m; ++y) {
                T[m + x][y] = 1;
            }
        }

        // Exponentiate the transition matrix to power (n - 2)
        T = power(T, n - 2);

        // Initial vector after 2 elements
        vector<long long> init(sz, 0);
        for (int x = 0; x < m; ++x) {
            init[x] = x;           // (x, next_down) has x valid preceding values
            init[m + x] = m - 1 - x; // (x, next_up) has m - 1 - x valid preceding values
        }

        // Multiply initial vector by T^(n-2)
        long long total_ways = 0;
        for (int j = 0; j < sz; ++j) {
            long long ways_for_j = 0;
            for (int i = 0; i < sz; ++i) {
                ways_for_j = (ways_for_j + init[i] * T[i][j]) % MOD;
            }
            total_ways = (total_ways + ways_for_j) % MOD;
        }

        return total_ways;
    }
};