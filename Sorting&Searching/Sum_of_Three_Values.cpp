#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;

ll MOD = 998244353;
double eps = 1e-12;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll binExpIter(ll a, ll b) {
    ll temp = 1;
    while (b > 0) {
        if (b & 1) temp = (temp * 1LL * a) % MOD;
        a  = (a * 1LL * a) % MOD;
        b >>= 1;
    }
    return temp % MOD;
}

ll inv(ll n) { return binExpIter(n, MOD - 2) % MOD; }

void solve(){
    ll n, x; cin >> n >> x;
    vector<pair<ll,ll>> a(n);
    forn(i,n){
        cin >> a[i].fi; a[i].se = i;
    }
    sort(all(a));
    forn(i,n){
        forsn(j,i+1,n){
            ll tgt = x - a[i].fi - a[j].fi;
            auto it = lower_bound(a.begin() + j + 1, a.end(), make_pair(tgt, 0LL));
            if(it != a.end() && it->fi == tgt){
                cout << a[i].se+1 << ' ' << a[j].se + 1 << ' ' << it->se + 1 << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(){
    fast_cin();
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}