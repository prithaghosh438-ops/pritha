
class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        if (sz[pa] < sz[pb])
            swap(pa, pb);

        parent[pb] = pa;
        sz[pa] += sz[pb];
    }

    vector<bool> areConnected(int n, int threshold,
                              vector<vector<int>>& queries) {

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Connect cities having a common divisor > threshold
        for (int d = threshold + 1; d <= n; d++) {
            for (int j = 2 * d; j <= n; j += d) {
                unite(d, j);
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};
