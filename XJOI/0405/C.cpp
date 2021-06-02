#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int T;
int N, M;
int a[2010],w[2010],v[2010];
const LL INF = 1e11;
int id[2010][2010];
int id2[2010];
int MM;
LL f[2010], dp[2010][2010];

LL solve(int L,int R) {
    if (dp[L][R] != -1) {
        return dp[L][R];
    }
    if (id2[L] == 1 && id2[R] == 1) {
        return dp[L][R] = 0;
    }
    if (id[L][R] == -1 && id2[L] == id2[R]) {
        return INF;
    }
    LL ret = 0;
    bool print = (L == 6 && R == 7);
    if (id2[L] != id2[R]) {
        for (int i=id2[L]+1;i<id2[R];i++) {
            ret += solve(a[i - 1] + 1, a[i]);            
        }
        ret += solve(L, a[id2[L]]);
        ret += solve(a[id2[R] - 1] + 1, R);
    } else {
        ret = INF;
        int len = (R - L + 1);
        for (int d=1;d<L;d++) {
            LL tmp = f[d] * len;
            ret = min(ret, solve(L - d, R - d) + tmp);
        }
    }
    //printf("dp[%d][%d]=%lld\n",L,R,ret);
    return dp[L][R] = ret;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N, &M);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=M;i++) {
            scanf("%d%d",&v[i],&w[i]);
        }
        f[0] = 0;
        MM = a[N];
        for (int i=1;i<=MM;i++) {
            f[i] = INF;
        }
        for (int i=1;i<=M;i++) {
            for (int j=w[i];j<=MM;j++) {
                f[j] = min(f[j], f[j - w[i]] + v[i]);
            }
        }
        
        /*
        for (int i=1;i<=MM;i++) {
            printf("f[%d]=%lld\n",i,f[i]);
        }
        */
        
        
        for (int i=1;i<=MM;i++) {
            for (int j=i;j<=MM;j++) {
                id[i][j] = -1;
            }
        }
        a[0] = 0;
        for (int i=1;i<=N;i++) {
            int L = a[i - 1] + 1, R = a[i];
            for (int j=L;j<=R;j++) {
                id[L][j] = i;
                id[j][R] = i;
                id2[j] = i;
            }
        }
        for (int i=1;i<=MM;i++) {
            for (int j=1;j<=MM;j++) {
                dp[i][j] = -1;
            }
        }
        LL ret = solve(1, MM);
        if (ret >= INF) {
            puts("-1");
        } else {
            printf("%lld\n",ret);
        }
    }
}

/*
1 
2 2
1 3
1 1
1 2
*/