#include <bits/stdc++.h>

using namespace std;

int N, K;
int L[1000010], H[1000010], W[1000010];
typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;

void read(int *v) {
    for (int i=1;i<=K;i++) {
        scanf("%d",v + i);
    }
    int A, B, C, D;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    for (int i=K+1;i<=N;i++) {
        v[i] = (1LL * A * v[i - 2] + 1LL * B * v[i - 1] + C) % D + 1;
    }
}

int conn(int L1,int R1,int L2,int R2) {
    return max(0, min(R1, R2) - max(L1, L2));
}

multiset<pii> s;

//(how many, x intersect)
pii fuck(int L,int R) {
    int ret1 = 0, ret2 = 0;
    pii p(L, -1e9);
    int minL = L, maxR = R;
    while(!s.empty()) {
        auto it = s.lower_bound(p);
        if (it == s.end() || it->first > R) break;
        minL = min(minL, it->first);
        maxR = max(maxR, it->second);
        ret1++;
        ret2 += conn(L, R, it->first, it->second);
        s.erase(it);
    }
    if (!s.empty()) {
        auto it = s.lower_bound(p);
        if (it != s.begin()) {
            --it;
            //printf("haha %d %d\n",it->first,it->second);
            if (it->second >= L) {
                ret1++;
                ret2 += conn(L, R, it->first, it->second);
                minL = min(minL, it->first);
                maxR = max(maxR, it->second);
                s.erase(it);
            }
        }
    }
    //printf("%d %d\n",ret1,ret2);
    s.insert(pii(minL, maxR));
    return pii(ret1, ret2);
}

int main() {
    freopen("A2_test.txt","r",stdin);
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d%d",&N,&K);
        read(L);
        //for (int i=1;i<=N;i++) printf("%d ", L[i]);puts("");
        read(W);
        //for (int i=1;i<=N;i++) printf("%d ", W[i]);puts("");
        read(H);
        //for (int i=1;i<=N;i++) printf("%d ", H[i]);puts("");
        LL peri = 2 * (W[1] + H[1]);
        LL ans = peri;
        s.clear();
        s.insert(pii(L[1], L[1] + W[1]));
        //printf("insert %d %d\n",L[1],L[1]+W[1]);
        for (int i=2;i<=N;i++) {
            auto ret = fuck(L[i], L[i] + W[i]);
            int intersect_cnt = ret.first, x_intersect = ret.second;
            peri += 2 * (W[i] - x_intersect);
            peri += 2LL * (1 - intersect_cnt) * H[i];
            peri = (peri % MOD + MOD) % MOD;
            //printf("peri = %lld\n", peri);
            ans = ans * peri % MOD;
        }
        printf("Case #%d: %lld\n",T,ans);
    }
}