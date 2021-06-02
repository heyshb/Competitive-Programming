#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,K;
vector<int>ans;

void solve(int L,int R) {
    //printf("solve %d %d\n",L,R);
    int len = R - L + 1;
    if (len == K) {
        for (int i=L;i<=R;i++) {
            ans.push_back(i);
        }
        return;
    }
    int d = len / K;
    for (int i=L;i<=R;i+=d) {
        solve(i, i + d - 1);
    }
    //printf("here %d %d\n",L,R);
    for (int i=L;i<L+d;i++) {
        /*
        for (int j=i;j<=R;j+=d) {
            ans.push_back(j);
        } */
        int now = i;
        for (int j=0;j<K;j++) {
            ans.push_back(now);
            now += (d + 1);
            if (now >= L + (j + 2) * d) {
                now -= d;
            }
        }
    }
}

bool check(int N,int K) {
    for (int i=1;i<=10;i++) {
        N /= __gcd(N, K);
    }
    return N == 1;
}

int main() {
    for (N=2;N<=1000;N++) {
        for (K=2;K<=N;K++) {
            if (N % K != 0) continue;
            if (!check(N,K)) {
                continue;
            }
            LL NN = 1;
            while(NN % N != 0) NN *= K;
            printf("%d %d %lld\n",N,K,NN);
            if (NN < 0) break;
        }
    }
}