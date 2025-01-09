#include<bits/stdc++.h>
using namespace std;

struct node{
    long long lazy, sum;
    node(): lazy(0), sum(0){};
};

long long arr[200000];
node tree[800400];

node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

void push(int p, int l, int r){
    if(tree[p].lazy){
        tree[p].sum += (r-l)*tree[p].lazy;

        if(r - l > 1){
            tree[p<<1].lazy += tree[p].lazy;
            tree[p<<1|1].lazy += tree[p].lazy;
        }
    }
    tree[p].lazy = 0;
}

void build(int p, int l, int r){
    if(r-l == 1){
        tree[p].sum = arr[l];
        return;
    }
    int mid = (l + r)/2;
    build(p<<1, l, mid);
    build(p<<1|1, mid, r);
    tree[p] = merge(tree[p<<1], tree[p<<1|1]);
}

void update(int p, int l, int r, int lq, int rq, long long upd){
    push(p, l, r);
    if(l >= rq || r <= lq) return;
    if(lq <= l && r <= rq){
        tree[p].lazy += upd;
        push(p, l, r);
        return;
    }
    int mid = (l + r)/2;
    update(p<<1, l, mid, lq, rq, upd);
    update(p<<1|1, mid, r, lq, rq, upd);
    tree[p] = merge(tree[p<<1], tree[p<<1|1]);
}

node query(int p, int l, int r, int lq, int rq){
    push(p, l, r);
    if(lq >= r || rq <= l) return node();
    if(lq <=l && r <= rq){
        return tree[p];
    }
    int mid = (l + r)/2;
    return merge(query(p<<1, l, mid, lq, rq), query(p<<1|1, mid, r, lq, rq));
}

int main(){
    int n,q; cin >> n >> q;
    for(int i=0; i<n; i++) cin >> arr[i];
    build(1, 0, n);
    while(q--){
        int ch; cin >> ch;
        if(ch == 1){
            long long u;
            int a, b; cin >> a >> b >> u;
            update(1, 0, n, a-1, b, u);
        }else{
            int p; cin >> p;
            cout << query(1, 0, n, p-1, p).sum << '\n';
        }
    }
    return 0;
}