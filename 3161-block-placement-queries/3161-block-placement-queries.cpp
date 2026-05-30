class SegmentTree {
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }
};


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxCoord = 0;
        for (const auto& q : queries) {
            maxCoord = max(maxCoord, q[1]);
        }
        // Add a safe upper bound margin
        maxCoord = max(maxCoord, 50005);

        SegmentTree st(maxCoord + 1);
        
        // tracking obstacle positions
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(maxCoord);
        
        // Initial gap spanning from 0 to maxCoord
        st.update(1, 0, maxCoord, maxCoord, maxCoord);

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                // Find adjacent obstacles using binary search
                auto it = obstacles.upper_bound(x);
                int R = *it;
                int L = *prev(it);
                
                // Remove the old gap at R
                st.update(1, 0, maxCoord, R, 0);
                
                // Insert two new split gaps
                st.update(1, 0, maxCoord, x, x - L);
                st.update(1, 0, maxCoord, R, R - x);
                
                obstacles.insert(x);
                
            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];
                
                // Find the closest obstacle strictly less than or equal to x
                auto it = obstacles.upper_bound(x);
                int L = *prev(it);
                
                // 1. Query the max gap completely to the left of obstacle L
                int maxGapLeft = st.query(1, 0, maxCoord, 0, L);
                
                // 2. Check the remaining partial gap between obstacle L and x
                int lastGap = x - L;
                
                int maxAvailableGap = max(maxGapLeft, lastGap);
                
                results.push_back(maxAvailableGap >= sz);
            }
        }

        return results;
        
    }
};