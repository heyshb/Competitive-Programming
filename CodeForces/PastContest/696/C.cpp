#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
void add(LL &x, LL y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class matrix {
public:
    LL val[3][3];
    matrix(){
        memset(val, 0, sizeof(val));
    }
    friend matrix operator * (matrix m1, matrix m2) {
        matrix ret;
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < 3; j++) {
                    add(ret.val[i][j], m1.val[i][k] * m2.val[k][j] % MOD);
                }
            }
        }
        return ret;
    };
};

matrix E;

void print(matrix a) {
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            printf("%9lld ",a.val[i][j]);
        }
        puts("");
    }
}

matrix quick_pow(matrix a, LL x) {
    matrix ret;
    ret.val[0][0] = ret.val[1][1] = ret.val[2][2] = 1;
    while(x) {
        if (x & 1) ret = ret * a;
        a = a * a;
        x >>= 1;
    }
    return ret;
}

int main() {
    E.val[0][0] = E.val[1][1] = E.val[2][2] = 1;
    matrix fuck;
    LL qaq = (MOD + 1) / 2;
    fuck.val[0][0] = qaq;
    fuck.val[0][1] = qaq;
    fuck.val[1][0] = qaq;
    fuck.val[1][2] = qaq;
    fuck.val[2][1] = qaq;
    fuck.val[2][2] = qaq;
    print(fuck);
    print(fuck * fuck);
    int K;
    LL x;
    scanf("%d",&K);
    while(K--) {
        scanf("%lld",&x);
        E = E * quick_pow(fuck, x);
    }
    LL ans = E.val[1][1];
    printf("%lld\n",ans);
}