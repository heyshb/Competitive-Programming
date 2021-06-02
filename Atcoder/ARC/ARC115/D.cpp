#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 5010;
int N, M;
set<int> d[MAXN];
const int MOD = 998244353;
int C[MAXN + 1][MAXN + 1];

void XOR(set<int> &x, set<int> &dd) {
    for (auto &t: dd) {
        if (x.find(t) != x.end()) {
            x.erase(t);
        } else {
            x.insert(t);
        }
    }
}

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    C[0][0] = 1;
    for (int i=1;i<=MAXN;i++) {
        C[i][0] = 1;
        for (int j=1;j<=i;j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= MOD) C[i][j] -= MOD;
        } 
    }
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        set<int> x;
        x.insert(u);
        x.insert(v);
        for (int i=N;i>=1;i--) {
            if (x.find(i) != x.end()) {
                if (!d[i].empty()) {
                    XOR(x, d[i]);
                } else {
                    d[i] = x;
                    break;
                }
            }
        }
        int cnt = 0;
        for (int i=1;i<=N;i++) {
            if (!d[i].empty()) {
                cnt++;
            }
        }
        int po = quick_pow(2, M - cnt);
        for (int K=0;K<=N;K++) {
            if (K > cnt) {
                puts("0");
                continue;
            }
            int way = 1LL * C[cnt][K] * po % MOD;
        }
    }
}