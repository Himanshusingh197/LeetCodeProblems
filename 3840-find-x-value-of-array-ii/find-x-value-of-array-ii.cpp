class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left part
        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes = whole left + prefix of right
        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int p, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(nums, p << 1, l, mid);
        build(nums, p << 1 | 1, mid + 1, r);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    void update(int p, int l, int r, int idx, int value) {
        if (l == r) {
            int rem = value % k;

            tree[p] = Node();

            tree[p].prod = rem;
            tree[p].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(p << 1, l, mid, idx, value);
        else
            update(p << 1 | 1, mid + 1, r, idx, value);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr)
            return tree[p];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(p << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(p << 1 | 1, mid + 1, r, ql, qr);

        Node left = query(p << 1, l, mid, ql, qr);
        Node right = query(p << 1 | 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = K;

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};