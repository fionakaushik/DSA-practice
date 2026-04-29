from typing import List

class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        H = n + 1
        NEG = -10**30

        # pref[c][k] = sum of grid[0..k-1][c]
        pref = [[0] * H for _ in range(n)]
        for c in range(n):
            for r in range(n):
                pref[c][r + 1] = pref[c][r] + grid[r][c]

        # dp[left][cur]:
        # after deciding columns up to current column,
        # previous column black height = left,
        # current column black height = cur,
        # and scores of columns before current are fixed.
        dp = [[NEG] * H for _ in range(H)]

        # virtual column -1 has height 0
        for cur in range(H):
            dp[0][cur] = 0

        # Process columns 0 .. n-2.
        # When choosing height `right` for column col+1,
        # contribution of column col becomes fixed.
        for col in range(n - 1):
            S = pref[col]
            ndp = [[NEG] * H for _ in range(H)]

            for cur in range(H):
                # prefix_best[x] = max dp[left][cur] for left <= x
                prefix_best = [NEG] * H
                best = NEG
                for left in range(H):
                    best = max(best, dp[left][cur])
                    prefix_best[left] = best

                # suffix_best[x] = max value for left >= x,
                # including contribution when max(left, right) = left
                suffix_best = [NEG] * (H + 1)
                best = NEG
                for left in range(H - 1, -1, -1):
                    val = dp[left][cur]
                    if left > cur:
                        val += S[left] - S[cur]
                    best = max(best, val)
                    suffix_best[left] = best

                for right in range(H):
                    # Case 1: left <= right, so max(left, right) = right
                    val1 = prefix_best[right]
                    if right > cur:
                        val1 += S[right] - S[cur]

                    # Case 2: left > right, handled by suffix_best[right + 1]
                    val2 = suffix_best[right + 1]

                    ndp[cur][right] = max(val1, val2)

            dp = ndp

        # Finish last column with virtual right boundary height 0
        ans = 0
        S = pref[n - 1]

        for left in range(H):
            for cur in range(H):
                val = dp[left][cur]
                if left > cur:
                    val += S[left] - S[cur]
                ans = max(ans, val)

        return ans
        