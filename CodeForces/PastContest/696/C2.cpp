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
    LL val[2][2];
    matrix(){
        memset(val, 0, sizeof(val));
    }
    friend matrix operator * (matrix m1, matrix m2) {
        matrix ret;
        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    add(ret.val[i][j], m1.val[i][k] * m2.val[k][j] % MOD);
                }
            }
        }
        return ret;
    };
};

matrix E;

void print(matrix a) {
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) {
            printf("%9lld ",a.val[i][j]);
        }
        puts("");
    }
}

matrix quick_pow(matrix a, LL x) {
    matrix ret;
    ret.val[0][0] = ret.val[1][1] = 1;
    while(x) {
        if (x & 1) ret = ret * a;
        a = a * a;
        x >>= 1;
    }
    return ret;
}

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

int main() {
    int K;
    scanf("%d",&K);
    E.val[0][0] = 1;
    E.val[0][1] = 1;
    E.val[1][0] = 2;
    matrix ans;
    LL q = 2;
    while(K--) {
        LL tmp;
        scanf("%lld",&tmp);
        E = quick_pow(E, tmp);
        q = quick_pow(q, tmp) % MOD;
    }
    //printf("%lld %lld\n",E.val[0][0],E.val[1][0]);
    q = q * (MOD + 1) / 2 % MOD;
    LL v1 = (MOD + 1) / 2;
    LL v2 = MOD - (MOD + 1) / 4;
    //printf("%lld %lld\n",E.val[0][0] * v1 % MOD,E.val[1][0] * v2 % MOD);
    LL p = (v1 * E.val[0][0] + v2 * E.val[1][0]) % MOD;
    printf("%lld/%lld\n",p,q);
}