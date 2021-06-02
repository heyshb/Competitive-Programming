#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

const LL mod[3]={998244353,1000000007,1000000009};
const LL seed[3]={233,37,133};
const int MAXN = 200010;
int N, M;
int L1[MAXN],L2[MAXN],len[MAXN],R1[MAXN],R2[MAXN];
LL h1[MAXN],h2[MAXN],po[MAXN];
int sum[MAXN],tt;
char t[MAXN];
bool ok[MAXN];
int nxt[MAXN], pre[MAXN];

int main()
{
    scanf("%d",&N);
	scanf("%s",t + 1);
	scanf("%d",&M);
	for (int i=1;i<=M;i++) {
        scanf("%d%d%d",&L1[i],&L2[i],&len[i]);
        R1[i] = L1[i] + len[i] - 1;
        R2[i] = L2[i] + len[i] - 1;
        ok[i] = true;
    }
    sum[0] = 0;
    for (int i=1;i<=N;i++) {
        sum[i] = sum[i - 1] + (t[i] == '0');
    }
    nxt[N + 1] = N + 1;
    for (int i=N;i>=1;i--) {
        if (t[i] == '0') {
            nxt[i] = i;
        } else {
            nxt[i] = nxt[i + 1];
        }
    }
    for (int ii=0;ii<3;ii++) {
        LL MOD = mod[ii];
        LL SEED = seed[ii];
        po[0] = 1;
        for (int i=1;i<MAXN;i++) {
            po[i] = po[i - 1] * SEED  %  MOD;
        }
        int now = 0;
        for (int i=1;i<=N;i++) {
            if (t[i] == '1') {
                continue;
            }
            now++;
            h1[now] = (h1[now - 1] * SEED + ((i & 1) ? 1 : 2))  %  MOD;
            h2[now] = (h2[now - 1] * SEED + ((i & 1) ? 2 : 1))  %  MOD;
        }

        for (int i=1;i<=M;i++) {
            if (sum[R1[i]] - sum[L1[i] - 1] != sum[R2[i]] - sum[L2[i] - 1]) {
                ok[i] = false;
                continue;
            }
            int zero = sum[R1[i]]-sum[L1[i]-1];
            LL t1 = ((h1[sum[R1[i]]]-h1[sum[L1[i]-1]]*po[zero] % MOD) % MOD+MOD) % MOD;
            LL t2 = ((h1[sum[R2[i]]]-h1[sum[L2[i]-1]]*po[zero] % MOD) % MOD+MOD) % MOD;
            if (L1[i]  %  2 != L2[i]  %  2) {
                t2=((h2[sum[R2[i]]]-h2[sum[L2[i]-1]]*po[zero] % MOD) % MOD+MOD) % MOD;
            }
            if (t1 != t2) {
                ok[i] = false;
            }
        }
    }
	for (int i=1;i<=M;i++) {
        puts(ok[i] ? "Yes" : "No");
    }
}