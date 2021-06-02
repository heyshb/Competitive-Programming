#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

vector<int>e[300010];
int N;
const int MOD = 998244353;
LL f[300010][2][2];

void mul(LL &x, LL y) {
    x = (x * y) % MOD;
}

void dfs(int x,int fa) {
    /*
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            f[x][i][j] = 1;
        }
    }
    */
    for (auto t:e[x]) {
        if (t == fa) {
            continue;
        }
        dfs(t, x);
    }
    LL mul_all = 1, mul_no_11 = 1, mul_no_01_11 = 1;
    for (auto t:e[x]) {
        if (t == fa) {
            continue;
        }
        mul(mul_all, f[t][0][0] + f[t][0][1] + f[t][1][0] + f[t][1][1]);
        mul(mul_no_11, f[t][0][0] + f[t][0][1] + f[t][1][0]);
        mul(mul_no_01_11, f[t][0][0] + f[t][1][0]);
    }
    f[x][0][0] = f[x][0][1] = mul_all;
    f[x][1][0] = (mul_no_11 - mul_no_01_11 + MOD) % MOD;
    f[x][1][1] = mul_no_11;
    /*
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            printf("f[%d][%d][%d]=%lld\n",x,i,j,f[x][i][j]);
        }
    }
    */
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
    scanf("%d",&N);
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }    
    dfs(1, 0);
    LL ans = (f[1][1][0] + f[1][0][1]) % MOD;
    printf("%lld\n",(ans + MOD - 1) % MOD); 
}