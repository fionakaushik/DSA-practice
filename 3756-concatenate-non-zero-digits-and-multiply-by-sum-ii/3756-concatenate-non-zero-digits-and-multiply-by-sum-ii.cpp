class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // //brute gives TLE nad also wrongans on testcase 3
        // vector<int>ans;
        // for(int i =0;i<queries.size();i++)
        // {
        //     int l=queries[i][0];
        //     int r=queries[i][1];
        //     int len_substr=r-l+1;
        //     string x;
        //     string s1=s.substr(l,r-l+1);
        //     for(char ch:s1)
        //     {
        //         if (ch!='0')
        //             x+=ch;
        //     }
        //     if (x.empty()) {
        //         ans.push_back(0);
        //         continue;
        //     }

        //     int temp=stoi(x);
        //     int n = temp;
        //     int sum=0;
        //     while(n>0)
        //     {
        //         sum+=n%10;
        //         n/=10;
        //     }
        //     long long mod=1e9;
        //     ans.push_back((1LL*sum*temp)%mod);
        // }
        // return ans;

        //opTIMAL
        int m = s.length();
        long long MOD = 1e9 + 7;

        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix arrays:
        // prefSum: stores the sum of digits
        // prefX: stores the running concatenated value of non-zero digits modulo 10^9 + 7
        // nonZeroCount: stores the count of non-zero digits encountered so far
        vector<int> prefSum(m + 1, 0);
        vector<long long> prefX(m + 1, 0);
        vector<int> nonZeroCount(m + 1, 0);

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            prefSum[i + 1] = prefSum[i] + digit;
            
            if (digit != 0) {
                prefX[i + 1] = (prefX[i] * 10 + digit) % MOD;
                nonZeroCount[i + 1] = nonZeroCount[i] + 1;
            } else {
                prefX[i + 1] = prefX[i];
                nonZeroCount[i + 1] = nonZeroCount[i];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            // 1. Get the sum of digits in O(1)
            long long currentSum = prefSum[r + 1] - prefSum[l];

            // 2. Get the number of non-zero digits in this range
            int cnt = nonZeroCount[r + 1] - nonZeroCount[l];

            if (cnt == 0) {
                ans.push_back(0);
                continue;
            }

            // 3. Extract the concatenated integer x in O(1) using modular arithmetic
            long long x = (prefX[r + 1] - (prefX[l] * pow10[cnt]) % MOD + MOD) % MOD;

            // 4. Calculate total answer for the query
            long long finalAns = (x * currentSum) % MOD;
            ans.push_back(finalAns);
        }

        return ans;

    }
};