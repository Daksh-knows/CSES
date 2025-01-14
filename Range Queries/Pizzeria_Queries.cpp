#include<bits/stdc++.h>
using namespace std;

/**
 * Observation : 
 * p[a] + |a- b| 
 * if(b <= a) p[a] + a - b
 * else p[a] + b - a = p[a] - a + b
 * Two separate segment trees (or similar structures) can be used:
 * Tree 1 : Tracks p[a] - a
 * Tree 2 : Tracks p[a] + a
 * Min  Price=min(Tree 1 query(1,b)+b,Tree 2 query(b,n)−b)
 */

const int inf = 1e9 + 1e5 + 1e2;

struct node{
    int val, idx, left, right;
    node() : val(0), idx(0), left(inf), right(inf) {};
    node(int val_, int idx_) : val(val_), idx(idx_), left(val_ + idx_), right(val_ - idx_) {};
};
node operator+(const node &a, const node &b){
    node c;
    c.left = min(a.left, b.left);
    c.right = min(a.right, b.right);
    return c;
}

int n,q,a[200400];
node t[800400];

void build(int p, int l, int r){
    if(r - l == 1){
        t[p] = node(a[l], r);
        return;
    }
    int m = (l + r)/2;
    build(p<<1, l, m);
    build(p<<1|1, m, r);
    t[p] = t[p<<1] + t[p<<1|1];
}

void modify(int p, int l, int r, int idx, int val_){
    if(r-l == 1){
        t[p] = node(val_, r);
        return;
    }
    int m = (l + r)/2;
    if(idx < m){
        modify(p<<1, l, m, idx, val_);
    }else{
        modify(p<<1|1, m, r, idx, val_);
    }
    t[p] = t[p<<1] + t[p<<1|1];
}

node query(int p, int l, int r, int x, int y){
    if(r <= x || l >= y) return node();
    if(x <= l && r <= y) return t[p];
    int m = (l + r)/2;
    return query(p<<1, l, m, x, y) + query(p<<1|1, m, r, x , y);
}

int main(){
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];
    build(1, 0, n);
    for(int i=1; i<= 15; i++){
        // cout << i << ' ' << t[i].val << ' ' << t[i].idx << ' ' << t[i].left << ' ' << t[i].right << '\n';
    }
    while(q--){
        int ch; cin >> ch;
        if(ch == 1){
            int z, upd; cin >> z >> upd;
            --z; modify(1, 0, n, z, upd);
        }else{
            int z; cin >> z;
            auto ql = query(1, 0, n, z, n);
            auto qr = query(1, 0, n, 0, z);
            int res = min(ql.left - z, qr.right + z);
            cout << res << '\n';
        }
    }
    return 0;
}