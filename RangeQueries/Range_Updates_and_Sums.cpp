#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    struct Node {
        long long sum = 0;   // Sum of the segment
        long long lazy_add = 0; // Lazy addition value
        long long lazy_set = -1; // Lazy set value (-1 means no set operation pending)
    };

    vector<Node> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy_set != -1) {
            // Apply lazy set operation
            tree[node].sum = (end - start + 1) * tree[node].lazy_set;
            if (start != end) {
                // Propagate lazy set
                tree[node * 2].lazy_set = tree[node].lazy_set;
                tree[node * 2 + 1].lazy_set = tree[node].lazy_set;
                tree[node * 2].lazy_add = 0;
                tree[node * 2 + 1].lazy_add = 0;
            }
            tree[node].lazy_set = -1;
        }
        if (tree[node].lazy_add != 0) {
            // Apply lazy add operation
            tree[node].sum += (end - start + 1) * tree[node].lazy_add;
            if (start != end) {
                // Propagate lazy add
                tree[node * 2].lazy_add += tree[node].lazy_add;
                tree[node * 2 + 1].lazy_add += tree[node].lazy_add;
            }
            tree[node].lazy_add = 0;
        }
    }

    void update_range_add(int node, int start, int end, int l, int r, long long value) {
        push(node, start, end);
        if (start > r || end < l) return; // No overlap
        if (start >= l && end <= r) { // Total overlap
            tree[node].lazy_add += value;
            push(node, start, end);
            return;
        }
        // Partial overlap
        int mid = (start + end) / 2;
        update_range_add(node * 2, start, mid, l, r, value);
        update_range_add(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    }

    void update_range_set(int node, int start, int end, int l, int r, long long value) {
        push(node, start, end);
        if (start > r || end < l) return; // No overlap
        if (start >= l && end <= r) { // Total overlap
            tree[node].lazy_set = value;
            push(node, start, end);
            return;
        }
        // Partial overlap
        int mid = (start + end) / 2;
        update_range_set(node * 2, start, mid, l, r, value);
        update_range_set(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    }

    long long query_range(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > r || end < l) return 0; // No overlap
        if (start >= l && end <= r) return tree[node].sum; // Total overlap
        // Partial overlap
        int mid = (start + end) / 2;
        long long left_sum = query_range(node * 2, start, mid, l, r);
        long long right_sum = query_range(node * 2 + 1, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

    void update_add(int l, int r, long long value) {
        update_range_add(1, 0, n - 1, l, r, value);
    }

    void update_set(int l, int r, long long value) {
        update_range_set(1, 0, n - 1, l, r, value);
    }

    long long query(int l, int r) {
        return query_range(1, 0, n - 1, l, r);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].sum = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
        }
    }

    void build(vector<int>& arr) {
        build(arr, 1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segtree(n);
    segtree.build(arr);

    while (q--) {
        int type, a, b, x;
        cin >> type >> a >> b;
        a--, b--; // Convert to 0-based indexing
        if (type == 1) {
            cin >> x;
            segtree.update_add(a, b, x);
        } else if (type == 2) {
            cin >> x;
            segtree.update_set(a, b, x);
        } else if (type == 3) {
            cout << segtree.query(a, b) << "\n";
        }
    }

    return 0;
}
