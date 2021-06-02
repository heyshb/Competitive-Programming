#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int MAXN = 110;
int N, M, Q;
int L[4010];
class matrix {
public:
    int N, M;
    LL v[MAXN][MAXN];
    matrix() {
        memset(v, 0, sizeof(v));
    }
    void print() {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                printf("%3lld",v[i][j]);
            }
            puts("");
        }
    }
    friend matrix operator * (matrix m1, matrix m2) {
        //printf("(%d,%d)*(%d,%d)",m1.N,m1.M,m2.N,m2.M);
        assert(m1.M == m2.N);
        matrix ret;
        ret.N = m1.N;
        ret.M = m2.M;
        for (int k=1;k<=m1.M;k++) {
            for (int i=1;i<=m1.N;i++) {
                for (int j=1;j<=m2.M;j++) {
                   ret.v[i][j] += m1.v[i][k] * m2.v[k][j] % MOD; 
                   ret.v[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
};

matrix m_qp(matrix a, LL x) {
    matrix ret;
    assert(a.N == a.M);
    ret.N = ret.M = a.N;
    for (int i=1;i<=ret.N;i++) {
        ret.v[i][i] = 1;
    }
    while(x) { 
        if (x & 1) {
            ret = ret * a;
        }
        a = a * a;
        x >>= 1;
    }
    return ret;
}

int main() {
    int N, M, Q;
    scanf("%d%d%d",&N, &M, &Q);
    matrix trans;
    trans.N = trans.M = N;
    for (int i=1;i<=N;i++) {
        scanf("%lld",&trans.v[i][i]);
    }
    for (int i=1;i<=M;i++) {
        int st, ed;
        scanf("%d%d",&st, &ed);
        trans.v[st][ed] = 1;
    }
    while(Q--) {
        int q;
        scanf("%d",&q);
        matrix ret = m_qp(trans, q);
        printf("%lld\n",ret.v[1][N]);
    }
}