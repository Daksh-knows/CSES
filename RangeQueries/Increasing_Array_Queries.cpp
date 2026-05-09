#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    vector<long long> cost(n + 1, 0);

    // Input array
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Precompute the cost array
    for (int i = 2; i <= n; i++) {
        cost[i] = cost[i - 1] + max(0, arr[i - 1] - arr[i]);
    }

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << cost[b] - cost[a] << "\n";
    }

    return 0;
}
