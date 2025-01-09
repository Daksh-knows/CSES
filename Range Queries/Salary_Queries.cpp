#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, q, arr[200400];
oset<pair<int,int>> s;

int main(){
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s.insert(make_pair(arr[i], i));
    }
    while(q--){
        char ch; cin >> ch;
        if(ch == '!'){
            int p, x; cin >> p >> x;
            --p;
            s.erase(make_pair(arr[p], p));
            arr[p] = x;
            s.insert(make_pair(arr[p], p));
        }else{
            int l, r; cin >> l >> r;
            int res = s.order_of_key(make_pair(r, n)) - s.order_of_key(make_pair(l-1,n));
            cout << res << '\n';
        }
    }
    return 0;
}