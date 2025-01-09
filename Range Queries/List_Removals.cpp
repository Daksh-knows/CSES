#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    find_by_order : kth element in the tree
    order_of_key: no. of elements less than key element
    lower_bound: first element >= key
    upper_bound: first element > key
*/

int main(){
    int n; cin >> n;
    oset<pair<int,int>> s;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        s.insert(make_pair(i, x));
    }
    for(int i=0; i<n; ++i){
        int r; cin >> r; -- r;
        auto it = s.find_by_order(r);
        cout << (*it).second << ' ';
        s.erase(it);
    }
    return 0;
}