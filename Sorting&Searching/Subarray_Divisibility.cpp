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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> u_map;

void _print(ll t)       {cerr << t;}
void _print(int t)      {cerr << t;}
void _print(string t)   {cerr << t;}
void _print(char t)     {cerr << t;}
void _print(ld t)       {cerr << t;}
void _print(double t)   {cerr << t;}
//void _print(ull t)      {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll szN = 4e6 + 7;
ll fact[szN + 1], invFact[szN + 1];

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
ll nCr(ll n, ll r) { return (((fact[n] * invFact[n - r]) % MOD) * invFact[r]) % MOD; }
bool isPrime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void preCompute() {
    fact[0] = 1, invFact[0] = 1;
    for (int i = 1; i <= szN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[szN] = inv(fact[szN]);
    for (int i = szN-1; i > 0; i--) {
        invFact[i] = (invFact[i + 1] * (i+1)) % MOD;
    }
}
ll __lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll mod_mul(ll a, ll b) { a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD; }
ll mod_add(ll a, ll b) { a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD; }
ll mod_sub(ll a, ll b) { a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD; }
ll mod_div(ll a, ll b) { a = a % MOD; b = b % MOD; return (mod_mul(a, inv(b)) + MOD) % MOD; }
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

//Until death, all defeat is psychological. - Napoleon Bonaparte

void solve(){
    ll n,x; cin >> n;
    v64 rem(n);  rem[0] = 1;
    ll ans = 0, curr = 0;
    forn(i,n){
        cin >> x;
        curr += x;
        curr %= n;
        curr += n;
        curr %= n;
        ans += (rem[curr]);
        rem[curr]++;
    }
    cout << ans << ln;
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