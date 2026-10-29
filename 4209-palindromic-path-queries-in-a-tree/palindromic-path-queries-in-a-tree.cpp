class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0);
        vector<int> sz(n, 1), heavy(n, -1);

        function<void(int, int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            int maxSize = 0;

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                dfs1(v, u);
                sz[u] += sz[v];

                if (sz[v] > maxSize) {
                    maxSize = sz[v];
                    heavy[u] = v;
                }
            }
        };

        dfs1(0, -1);

        vector<int> head(n), pos(n);
        int timer = 0;

        function<void(int, int)> dfs2 = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;

            if (heavy[u] != -1) {
                dfs2(heavy[u], h);
            }

            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u]) continue;
                dfs2(v, v);
            }
        };

        dfs2(0, 0);

        vector<int> seg(4 * n, 0);

        function<void(int, int, int)> build =
            [&](int node, int l, int r) {
                if (l == r) {
                    int u = -1;
                    // Map the position back to its node.
                    return;
                }
            };

        vector<int> atPos(n);
        for (int u = 0; u < n; u++) {
            atPos[pos[u]] = u;
        }

        function<void(int, int, int)> buildTree =
            [&](int node, int l, int r) {
                if (l == r) {
                    seg[node] = 1 << (s[atPos[l]] - 'a');
                    return;
                }

                int mid = (l + r) / 2;
                buildTree(node * 2, l, mid);
                buildTree(node * 2 + 1, mid + 1, r);

                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };

        buildTree(1, 0, n - 1);

        function<void(int, int, int, int, int)> update =
            [&](int node, int l, int r, int idx, int val) {
                if (l == r) {
                    seg[node] = val;
                    return;
                }

                int mid = (l + r) / 2;

                if (idx <= mid)
                    update(node * 2, l, mid, idx, val);
                else
                    update(node * 2 + 1, mid + 1, r, idx, val);

                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };

        function<int(int, int, int, int, int)> query =
            [&](int node, int l, int r, int ql, int qr) -> int {
                if (qr < l || r < ql) return 0;

                if (ql <= l && r <= qr) return seg[node];

                int mid = (l + r) / 2;

                return query(node * 2, l, mid, ql, qr) ^
                       query(node * 2 + 1, mid + 1, r, ql, qr);
            };

        auto pathMask = [&](int u, int v) {
            int mask = 0;

            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) {
                    swap(u, v);
                }

                mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }

            if (depth[u] > depth[v]) swap(u, v);

            mask ^= query(1, 0, n - 1, pos[u], pos[v]);

            return mask;
        };

        vector<bool> answer;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;

                int mask = pathMask(u, v);

                answer.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};