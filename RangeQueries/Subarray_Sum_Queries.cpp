#include<bits/stdc++.h>
using namespace std;

struct node{
    long long sum, pref, suff, sub;
    node(): sum(0), pref(0), suff(0), sub(0){};
    node(long long val): sum(val), pref(max(0LL,val)), suff(max(0LL,val)), sub(max(0LL,val)){};
};

node operator+(const node& a, const node &b){
    node c;
    c.sum = a.sum + b.sum;
    c.pref= max(a.pref, a.sum + b.pref);
    c.suff = max(b.suff, b.sum + a.suff);
    c.sub = max({a.sub, b.sub, a.suff + b.pref});
    return c;
}

long long n, q, a[200400], p, val_;
node t[800400];

void build(long long p, long long l, long long r){
    if(r - l == 1){
        t[p] = node(a[l]);
        return;
    }
    long long m = (l + r)/2;
    build(p<<1, l, m);
    build(p<<1|1, m, r);
    t[p] = t[p<<1] + t[p<<1|1];
}

void modify(long long p, long long l, long long r, long long idx, long long val){
    if(r-l == 1){
        t[p] = node(val);
        return;
    }
    long long m = (l+r)/2;
    if(idx < m){
        modify(p<<1, l, m, idx, val);
    }else{
        modify(p<<1|1, m, r, idx, val);
    }
    t[p] = t[p<<1] + t[p<<1|1];
}

int main(){
    cin >> n >> q;
    for(long long i=0; i<n; i++) cin >> a[i];
    build(1, 0, n);
    while(q--){
        cin >> p >> val_;
        --p;
        modify(1, 0, n, p, val_);
        cout << max({t[1].sub, t[1].pref, t[1].suff, t[1].sum}) << '\n';
    }
    return 0;
}