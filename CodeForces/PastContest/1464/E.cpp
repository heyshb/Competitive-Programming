#include <bits/stdc++.h>

using namespace std;

int sg[100010];
int cnt[100010];
vector<int>e[100010];
int N, M;
bool vis[522];
int inv[100010];
const int MOD = 998244353;
int P[522][522];

int dfs(int x) {
    vector<int>suf_sg;
    if (sg[x] != -1) return sg[x];
    for (auto t:e[x]) {
        suf_sg.push_back(dfs(t));
    }
    for (auto t:suf_sg) {
        vis[t] = true;
    }
    int ret = -1;
    for (int i=0;;i++) {
        if (!vis[i]) {
            ret = i;
            break;
        }
    }
    for (auto t:suf_sg) {
        vis[t] = false;
    }
    return sg[x] = ret;
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
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
    }
    for (int i=1;i<=N;i++) sg[i] = -1;
    for (int i=1;i<=N;i++) {
        //if (sg[i] == -1) {
            dfs(i);
        //}
    }
    int max_sg = 0;
    for (int i=1;i<=N;i++) {
        //printf("sg %d = %d\n",i,sg[i]);
        cnt[sg[i]]++;
        max_sg = max(max_sg, sg[i]);
    }
    int B = 1;
    while((((1 << B) - 1) & max_sg) != max_sg) B++;
    B = (1 << B) - 1;
    //printf("aaa %d %d\n",max_sg, B);
    assert(B <= 511);
    int inv_np1 = quick_pow(N + 1, MOD - 2);
    for (int i=0;i<=B;i++) {
        if (i == 0) P[i][B + 1] = 0;
        else P[i][B + 1] = inv_np1;
        for (int j=0;j<=B;j++) {
            int delta = i ^ j;
            if (!cnt[delta]) continue;
            P[i][j] = 1LL * cnt[delta] * (MOD - inv_np1) % MOD;
        }
        P[i][i] = (P[i][i] + 1) % MOD;
    }
    /*
    for (int i=0;i<=B;i++) {
        for (int j=0;j<=B+1;j++) {
            printf("%d ",P[i][j]);
        }
        puts("");
    }
    */
    for (int i=0;i<=B;i++) {
        if (P[i][i] == 0) {
            int idx = -1;
            for (int j=i+1;j<=B;j++) {
                if (P[j][i]) {
                    idx = j;
                    break; 
                }
            }
            if (idx == -1) break;
            for (int j=0;j<=B+1;j++) swap(P[i][j], P[idx][j]);
        }
        for (int j=i+1;j<=B;j++) {
            if (!P[j][i]) continue;
            int coe = 1LL * quick_pow(P[i][i], MOD - 2) * (MOD - P[j][i]) % MOD;
            for (int k=i;k<=B+1;k++) {
                P[j][k] = (P[j][k] + 1LL * P[i][k] * coe % MOD) % MOD;
            }
            assert(P[j][i] == 0);
        }
    }
    for (int i=B;i>0;i--) {
        if (!P[i][i]) continue;
        for (int j=i-1;j>=0;j--) {
            int coe = 1LL * quick_pow(P[i][i], MOD - 2) * (MOD - P[j][i]) % MOD;
            for (int k=i;k<=B+1;k++) {
                P[j][k] = (P[j][k] + 1LL * P[i][k] * coe % MOD) % MOD;
            }
        }
    }
    for (int i=0;i<=B;i++) {
        for (int j=0;j<=B;j++) {
            if (i != j) assert(P[i][j] == 0);
        }
    }
    printf("%lld\n",1LL * P[0][B+1] * quick_pow(P[0][0], MOD - 2) % MOD);
}