#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, n) for(int i=0; i<n; i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define fi first
#define se second


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
    cin >> t;
    while(t--) solve();
    return 0;
}

void rotate(vector<int>& a, int start, int pos){
    if(pos == 0) return;
    int idx = 0, n = a.size();
    vector<int> b;
    for(int i=0; i<pos; i++){
        b.pb(a[n-1-i]);
    }
    for(int i=n-1; i>=start + pos; i--) a[i] = a[i-pos];
    for(int i=start+pos-1; i>=start; i--) a[i] = b[idx++];
}

void solve(){
    int n, a, b; cin >> n >> a >> b;
    if(a + b > n){
        cout << "NO\n"; return;
    }
    if(a == b && a == 0){
        cout << "YES\n";
        forn(i,n) cout << i + 1 << " \n"[i == n-1];
        forn(i,n) cout << i + 1 << " \n"[i == n-1];
        return;
    }
    int x = min(a, b);
    if(x == 0){
        cout << "NO\n"; return;
    }
    int fixed = n - (a + b);
    cout << "YES\n";
    vector<int> ares, bres;
    for(int i=0; i<n; i++) {
        ares.pb(i + 1);
        bres.pb(i + 1);
    }
    rotate(ares, fixed, a);
    for(int i=0; i<n; i++){
        if(ares[i] == bres[i]) continue;
        if(ares[i] > bres[i]) a--;
        else b--;
    }
    assert(a == 0 && b == 0);
    for(int i=0; i<n; i++) cout << ares[i] << " \n"[i == n-1];
    for(int i=0; i<n; i++) cout << bres[i] << " \n"[i == n-1];
}