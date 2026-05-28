#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define forn(i, n) for(int i=0; i<n; i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define fi first
#define se second

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int szN = 1000100;
const int MOD = 1e9 + 7;
int ff[szN], iff[szN];
bool is_prime[szN];
vector<int> primes;

int binpow(int a, int x){
    int res = 1;
    while ( x > 0 ) {
        if ( x&1 ) {
            res = (res * a) % MOD;
        }
        a = ( a * a ) % MOD;
        x >>= 1;
    } 
    return res;
}

void preFact(){
    ff[0] = ff[1] = 1;
    for(int i = 2; i < szN; i++ ) {
        ff[i] = ( ff[ i - 1 ] * i ) % MOD;
    }
    iff[ szN - 1 ] = binpow( ff[szN - 1] , MOD - 2 );
    assert( ( ff[ szN - 1 ] * iff[ szN - 1 ] ) % MOD == 1 );
    for(int i = szN - 2; i >= 0; i-- ) {
        iff[i] = ( iff[ i + 1 ] * (i + 1)) % MOD;
    }
}

int nCr(int n, int r) {
    if( r > n || r < 0 ) return 0;
    int res = ff[n];
    res = ( res * iff[n-r] ) % MOD;
    res = ( res * iff[ r ] ) % MOD;
    return res;
}

void preSieve() {
    for (int i = 0; i < szN; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<szN; i++){
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i*i; j < szN; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void solve();

signed main(){
    // freopen("art.in", "r", stdin);
    // freopen("art.out", "w", stdout);
    // preFact();  preSieve();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n, k; cin >> n >> k;
    oset<int> st;
    for(int i=1; i<=n; i++) st.insert(i);
    int pos = 0;
    while(!st.empty()){
        pos = (pos + k)%sz(st);
        auto it = st.find_by_order(pos);
        cout << *it << ' ';
        st.erase(it);
    }
    cout << endl;
}