#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;
LL N, M, L, R, p, q;

LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}



class matrix {
public:
    LL v[2][2];
    matrix() {
        memset(v, 0, sizeof(v));
    }
    friend matrix operator * (matrix m1, matrix m2) {
        matrix ret;
        for (int k=0;k<2;k++) {
            for (int i=0;i<2;i++) {
                for (int j=0;j<2;j++) {
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
    ret.v[0][0] = ret.v[1][1] = 1;
    while(x) { 
        if (x & 1) {
            ret = ret * a;
        }
        a = a * a;
        x >>= 1;
    }
    return ret;
}

LL get_sum(LL x, LL m) {
    matrix mm;
    //printf("get_sum %lld %lld\n",x, m);
    mm.v[0][0] = mm.v[1][1] = q;
    mm.v[0][1] = mm.v[1][0] = p;
    mm = m_qp(mm, x);
    //printf("%lld %lld %lld\n",p,q,mm.v[0][m]);
    return mm.v[0][m];
}

int main() {
    scanf("%lld%lld%lld%lld",&N,&M,&L,&R);
    if (N % 2 == 1 && M % 2 == 1) {
        printf("%lld\n", quick_pow(R - L + 1, N * M));
        return 0;
    }
    p = q = (R - L + 1) / 2;
    if (L % 2 == R % 2) {
        if (L % 2 == 1) {
            p++;
        } else {
            q++;
        }
    }
    LL o_row, e_row, o_col, e_col;
    o_row = (N + 1) / 2;
    e_row = N - o_row;
    o_col = (M + 1) / 2;
    e_col = M - o_col;
    LL black, white;
    black = o_row * o_col + e_row * e_col;
    white = o_row * e_col + e_row * o_col;
    LL ans = get_sum(black, 1) * get_sum(white, 1) + get_sum(black, 0) * get_sum(white, 0);
    printf("%lld\n",ans % MOD);
}