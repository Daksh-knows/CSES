#include<bits/stdc++.h>
using namespace std;

struct node{
    long long maxm, idx;
    node(): maxm(0), idx(0) {};
    node(long long idx_, long long maxm_): idx(idx_), maxm(maxm_){};
};
node operator+(const node& a, const node& b){
    if(a.maxm == b.maxm){
        return node(min(a.idx, b.idx), a.maxm);
    }else if(a.maxm > b.maxm){
        return node(a.idx, a.maxm);
    }
    return node(b.idx, b.maxm);
}

node t[800400];
long long arr[200400];

void build(int p, int l, int r){
    if(r - l == 1){
        t[p] = node(l, arr[l]);
        return;
    }
    int m = (l + r)/2;
    build(p<<1, l, m);
    build(p<<1|1, m, r);
    t[p] = t[p<<1] +  t[p<<1|1];
}

int query(int p, int l, int r, long long req){
    if(t[p].maxm < req) return -1;
    if(r-l == 1){
        t[p].maxm -= req;
        return t[p].idx;
    }
    int mid = (l + r)/2;
    int ans = 0;
    if(t[p<<1].maxm >= req){
        ans = query(p<<1, l, mid, req);
    }else{
        ans = query(p<<1|1, mid, r, req);
    }
    t[p] = t[p<<1] + t[p<<1|1];
    return ans;
}

int main(){
    int n,m; cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> arr[i];
    build(1, 0, n);
    long long req;
    for(int i=0; i<m; ++i){
        cin >> req;
        cout << query(1, 0, n, req) + 1 << ' ';
    }
    return 0;
}
