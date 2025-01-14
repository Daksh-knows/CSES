#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200400;
int arr[MAXN], freq[MAXN], answer[MAXN], current_distinct = 0;
struct Query {
    int l, r, idx;
};

// Comparison function for sorting queries
bool compare(const Query &a, const Query &b) {
    int block_a = a.l / sqrt(MAXN);
    int block_b = b.l / sqrt(MAXN);
    if (block_a != block_b) return block_a < block_b;
    return (block_a & 1) ? a.r < b.r : a.r > b.r;
}

// Add element to the current range
void add(int x) {
    if (++freq[x] == 1) ++current_distinct;
}

// Remove element from the current range
void remove(int x) {
    if (--freq[x] == 0) --current_distinct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> compressed; // For coordinate compression
    vector<Query> queries(q);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        compressed.push_back(arr[i]);
    }

    // Coordinate compression
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(compressed.begin(), compressed.end(), arr[i]) - compressed.begin();
    }

    // Read queries
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // Convert to 0-based indexing
        queries[i].r--; // Convert to 0-based indexing
        queries[i].idx = i;
    }

    // Sort queries using Mo's order
    sort(queries.begin(), queries.end(), compare);

    // Mo's algorithm
    int l = 0, r = -1;
    for (const auto &query : queries) {
        while (r < query.r) add(arr[++r]);
        while (r > query.r) remove(arr[r--]);
        while (l < query.l) remove(arr[l++]);
        while (l > query.l) add(arr[--l]);

        answer[query.idx] = current_distinct;
    }

    // Output results
    for (int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
