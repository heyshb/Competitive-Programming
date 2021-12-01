
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define pd __gnu_pbds
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using namespace placeholders;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using il = initializer_list<T>;
 
template <class T> inline void mini(T& l, const T& r){l = min(l, r);}
template <class T> inline void maxi(T& l, const T& r){l = max(l, r);}
 
template <class T> void _dbg(const char* sdbg, T h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char* sdbg, T h, R... a){
    while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream& operator <<(ostream& os, const pair<L, R>& pr){
    return os << "(" << pr.st << "," << pr.nd << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& v){
    os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
    return V(b, e);}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gn(IT b, int n){
    return V(b, b + n);}
template <class T, class c = decltype(T().begin())> typename enable_if<!is_same<T, string>::value, ostream&>::type operator <<(ostream& os, T& v){
    return os << gr(all(v));}
template <class T, int I, int N> typename enable_if<I == N, void>::type TuplePrint(ostream& os, T val){
    os << get<N>(val);}
template <class T, int I, int N> typename enable_if<I < N, void>::type TuplePrint(ostream& os, T val){
    os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream& operator<<(ostream& os, tuple<Ts...> t){
    os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";}
 
#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif
 
//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;
 
constexpr int N = 1E5 + 10;
const ll M = 1E9 + 7;
 
int main(){
    int cas = 1;
    for (int casi = 1; casi <= cas; ++casi){
        int n, p;
        scanf("%d%d", &p, &n);
        vector s(n, 0);
        vector sz(p, 0);
        vector mark(p, 0);
        for (int i = 0; i < n; ++i)
            scanf("%d", &s[i]), --s[i], ++sz[s[i]], mark[s[i]] = i;
        int ans = 0;
        vector<pair<int, vector<int>>> res;
 
        int m;
        scanf("%d", &m);
        vector<pii> A, B;
        for (int i = 0; i < m; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            if (s[u] != s[v]) A.emplace_back(u, v);
            else B.emplace_back(u, v);
        }
 
        vector ban(n, 0);
        vector id(n, -1);
        array<ll, 64> e;
        for (int mask = 0; mask < (1 << A.size()); ++mask){
            vector<pair<int, vector<int>>> tres;
            int tans = p;
            for (int i = 0; i < A.size(); ++i){
                int u = mask >> i & 1 ? A[i].st : A[i].nd;
                if (!ban[u]) {
                    ban[u] = 1;
                    --sz[s[u]];
                    if (sz[s[u]] == 0)
                        --tans, tres.push_back({s[u], {}});
                }
            }
 
            map<int, vector<int>> a;
            vector<int> real;
            for (auto [u, v]: B){
                if (ban[u] || ban[v]) continue;
                if (id[u] == -1) id[u] = real.size(), a[s[u]].push_back(id[u]), real.push_back(u);
                if (id[v] == -1) id[v] = real.size(), a[s[v]].push_back(id[v]), real.push_back(v);;
                e[id[u]] |= 1ll << id[v];
                e[id[v]] |= 1ll << id[u];
            }
 
            for (auto& [S, b]: a){
                int tt = 0;
                ll t2 = 0;
                function<void(int, ll, ll)> dfs = [&](int d, ll cur, ll rem){
                    if (tt < d) tt = d, t2 = cur;
 
                    for (; rem; ){
                        int t = __builtin_ctzll(rem);
                        rem ^= 1ll << t;
                        if ((e[t] & cur) == cur){
                            dfs(d + 1, cur | 1ll << t, rem);
                        }
                    }
                };
                ll rem = 0;
                for (auto x: b) rem |= 1ll << x;
                dfs(0, 0, rem);
 
                tans += tt - 1;
                tres.push_back({S, {}});
                for (; t2; ) {
                    int t = __builtin_ctzll(t2);
                    t2 ^= 1ll << t;
                    tres.back().nd.push_back(real[t]);
                }
            }
            if (ans < tans) ans = tans, res = move(tres);
 
            for (auto [u, v]: B) e[id[u]] = e[id[v]] = 0;
            for (auto [u, v]: B) id[u] = id[v] = -1;
            for (int i = 0; i < A.size(); ++i){
                int u = mask >> i & 1 ? A[i].st : A[i].nd;
                if (ban[u]) ban[u] = 0, ++sz[s[u]];
            }
        }
        printf("%d\n", ans);
        vector<int> g;
        for (auto& [i, a]: res){
            mark[i] = -1;
            for (auto u: a) g.push_back(u);
        }
        for (int i = 0; i < p; ++i) if (mark[i] >= 0) g.push_back(mark[i]);
        for (int i = 0; i < g.size(); ++i)
            printf("%d%c", g[i] + 1, "\n "[i + 1 < g.size()]);
    }
    return 0;
}
 