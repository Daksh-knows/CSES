#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//Until death, all defeat is psychological. - Napoleon Bonaparte
ll n,m,p;

ll helper(ll i, ll j, string& s, string& t, vv64& dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    if(dp[i][j] != p+1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = helper(i-1, j-1, s, t, dp);
    }else{
        return dp[i][j] = 1 + min({helper(i-1, j, s, t, dp), helper(i, j-1, s, t, dp), helper(i-1, j-1, s, t, dp)});
    }
}

void solve(){
    string s,t; cin >> s >> t;
    n = s.size();
    m = t.size();
    p = max(n,m);
    /**
    vv64 dp(n+1, v64(m+1, p+1));
    // cout << helper(n-1, m-1, s, t, dp);
    forn(i,n+1) dp[i][0] = i;
    forn(j,m+1) dp[0][j] = j;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
    }
    cout << dp[n][m] << ln;
    */

    v64 prev(m+1), curr(m+1);
    forn(i,m+1) prev[i] = i;
    forsn(i,1,n+1){
        curr[0] = i;
        forsn(j,1,m+1){
            if(s[i-1] == t[j-1])
                curr[j] = prev[j-1];
            else
                curr[j] = 1+min({prev[j-1], curr[j-1], prev[j]});
        }
        prev = curr;
    }
    cout << prev[m] <<ln;
}
int main()
{
    fast_cin();
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}