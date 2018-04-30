#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

using ll = long long;
using ld = long double;

const int N = 1010, M = 1e9 + 7;

int a[N];
int f[N][N][2];
int P, G, A, B;
int e[N][N];

void add(int &a, int b) {
  a = (a + b) % M;
  if (a < 0) a += M;
}

void init() {
  a[0] = 1;
  for (int i = 2; i < N; i += 2) {
    for (int j = 0; j <= i - 2; ++j) {
      add(a[i], 1ll * a[j] * a[i - 2 - j] % M);
    }
  }
  debug(a[6]);
}

void clear() {
  for (int i = 0; i < P; ++i) fill_n(e[i], P, 0);
  for (int i = 0; i < P; ++i) {
    for (int j = 0; j < P; ++j) f[i][j][0] = f[i][j][1] = -1;
  }
}

//k == 0: i->any
//k == 1: i->j

int solve(int i, int j, int k) {
  debug(i, j, k, f[i][j][k]);
  if ((j - i) % 2 == 0) return 0;
  if (i > j) return 1;
  if (f[i][j][k] != -1) return f[i][j][k];
  int &ret = f[i][j][k];
  ret = 0;
  if (k == 1) {
    if (e[i][j]) return ret = 0;
    else {
      return ret = solve(i + 1, j - 1, 0);
    }
  } else {
    for (int x = i + 1; x <= j; x += 2) {
      add(ret, 1ll * solve(i, x, 1) * solve(x + 1, j, 0) % M);
    }
    return ret;
  }
}

void run() {
  int C;
  cin >> C;
  init();
  for (int _ = 1; _ <= C; ++_) {
    cin >> P >> G;
    clear();
    for (int i = 0; i < G; ++i) {
      cin >> A >> B;
      e[A][B] = 1;
      e[B][A] = 1;
    }
    debug(solve(0, P - 1, 1));
    debug(solve(0, P - 1, 0));
    printf("Case #%d: %d\n", _, solve(0, P - 1, 0)); 
  }
}

int main() {
	freopen("10_submit.in","r",stdin);
	freopen("10_submit_2.out","w",stdout);
  run();
  return 0;
}
