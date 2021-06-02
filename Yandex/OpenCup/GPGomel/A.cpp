#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N,K;
vector<LL>ans;

void solve(LL L,LL R) {
    //printf("solve %d %d\n",L,R);
    LL len = R - L + 1;
    if (len == K) {
        for (LL i=L;i<=R;i++) {
            ans.push_back(i);
        }
        return;
    }
    LL d = len / K;
    for (LL i=L;i<=R;i+=d) {
        solve(i, i + d - 1);
    }
    //printf("here %d %d\n",L,R);
    for (LL i=L;i<L+d;i++) {
        /*
        for (int j=i;j<=R;j+=d) {
            ans.push_back(j);
        } */
        LL now = i;
        for (LL j=0;j<K;j++) {
            ans.push_back(now);
            now += (d + 1);
            if (now >= L + (j + 2) * d) {
                now -= d;
            }
        }
    }
}

bool check(LL N,LL K) {
    for (int i=1;i<=10;i++) {
        N /= __gcd(N, K);
    }
    return N == 1;
}

int main() {
    scanf("%lld%lld",&N,&K);
    if (!check(N,K)) {
        puts("-1");
        return 0;
    }
    int NN = 1;
    while(NN % N != 0) NN *= K;
    solve(1, NN);
    assert(ans.size() % K == 0);
    printf("%d\n",ans.size() / K);
    
    /*
    for (int i=0;i<ans.size();i++) {
        ans[i] %= N;
        if (ans[i] == 0) {
            ans[i] = N;
        }
        printf("%lld",ans[i]);
        if (i % K == K - 1) {
            puts("");
        } else {
            printf(" ");
        }
    }
    
    vector<double>aa(N+1);
    srand(1997);
    for (int i=1;i<=N;i++) {
        aa[i] = 1.0 * rand();
        //printf("%.5lf\n",aa[i]);
    }
    for (int i=0;i<ans.size();i+=K) {
        double S = 0;
        for (int j=i;j<i+K;j++) {
            //printf("%d %.5lf\n",ans[j],aa[ans[j]]);
            S += aa[ans[j]];
        }
        for (int j=i;j<i+K;j++) {
            aa[ans[j]] = S / K;
        }
    }
    for (int i=1;i<=N;i++) {
        printf("%.5lf\n",aa[i]);
    }
    */
    
}