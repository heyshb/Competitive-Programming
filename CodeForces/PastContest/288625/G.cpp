#include <bits/stdc++.h>
 
using namespace std;
 
template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}
 
string to_string(string s) {
    return '"' + s + '"';
}
 
string to_string(bool a) {
    return a ? "T" : "F";
}
 
string to_string(const char* s) {
    return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
#define X first
#define Y second
 
using ll = long long;
using ld = long double;
 
const int B = 1e9 + 7;
 
ll n, k;
 
ll get(ll n, ll i) {
    if (i == 1) return n;
    return n / i + (n - 1) / i + 1;
}
 
ll get2(ll n, ll i, ll k) {
    //[ n/(i-1) + 1,n / i]
    ll r = n / i;
    ll l = n / (i + 1) + 1;
    if (l > k) {
        return 0;
    } else if (r > k) {
        r = k;
    }
    ll ans = 0;
    if (r * i == n) ans -= 1;
    ans += (r - l + 1) % B * (i + i + 1) % B;
    ans = (ans + B) % B;
    return ans;
}
 
ll get3(ll n, ll k) {
    if (n >= k) return 0;
    else return (k - n + B) % B;
}
 
void run() {
    scanf("%lld%lld", &n, &k);
    ll i = 1;
    ll ans = 0;
    for (i = 1; i * i <= n && i <= k; ++i) {
        debug(n, i, get(n, i));
        ans = (ans + get(n, i)) % B;
        if (i * i < n) {
            debug(get2(n, i, k), n, i);
            ans = (ans + get2(n, i, k)) % B;
        }
    }
    ans = (ans + get3(n, k)) % B;
    printf("%lld\n", ans);
}
 
int main() {
    run();
    return 0;
}