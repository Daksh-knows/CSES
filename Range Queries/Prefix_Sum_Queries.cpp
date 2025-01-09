#include<bits/stdc++.h>
using namespace std;

struct node{
    long long sum, maxm;
    node(): sum(0), maxm(0){};
    node(long long sum_): sum(sum_), maxm(max(sum_, 0LL)){};
};

node operator+(const node &a, const node &b){
    node c;
    c.sum = a.sum + b.sum;
    c.maxm = max({0LL, a.maxm, a.sum + b.maxm});
    return c;
}

int n,q;
long long arr[200400];
node t[800400];

void build(int p, int l, int r){
    if(r - l == 1){
        t[p] = node(arr[l]);
        return;
    }
    int mid = (l + r)/2;
    build(p<<1, l, mid);
    build(p<<1|1, mid, r);
    t[p] = t[p<<1] + t[p<<1|1];
}

void modify(int p, int l, int r, int idx, long long val){
    if(r - l == 1){
        t[p] = node(val);
        return;
    }
    int mid = (l + r)/2;
    if(idx < mid){
        modify(p<<1, l, mid, idx, val);
    }else{
        modify(p<<1|1, mid, r, idx, val);
    }
    t[p] = t[p<<1] + t[p<<1|1];
}

node query(int p, int l, int r, int ql, int qr){
    if(l >= qr || r <= ql) return node();
    if(ql <= l && r <= qr){
        return t[p];
    }
    int mid = (l + r)/2;
    return query(p<<1, l, mid, ql, qr) + query(p<<1|1, mid, r, ql, qr);
}

int main(){
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> arr[i];
    build(1, 0, n);
    
    while(q--){
        int ch; cin >> ch;
        if(ch == 1){
            long long x;
            int p;
            cin >> p >> x; --p;
            modify(1, 0, n, p, x);
        }else{
            int l, r; cin >> l >> r;
            --l;
            auto res = query(1, 0, n, l, r);
            cout << res.maxm << '\n';
        }
    }
    return 0;
}