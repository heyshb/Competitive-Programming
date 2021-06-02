#include <bits/stdc++.h>

using namespace std;

vector<int>prime;
const int M = 2000000;
bool isprime[M + 10];
int mi[M + 10];
int ans[M + 10];
typedef pair<int,int> pii;
int prime_fac[M + 10], mul[M + 10];

int main() {
    memset(isprime, true, sizeof(isprime));
    for (int i=2;i<=M;i++) {
        ans[i] = -1;
        if (isprime[i]) {
            mi[i] = i;
            prime.push_back(i);
        }
        for (auto &t: prime) {
            if (i * t > M) break;
            isprime[i * t] = false;
            mi[i * t] = t;
            if (i % t == 0) break;
        }
    }
    for (int i=2;i<=M;i++) {
        int tmp = i;
        mul[i] = 1;
        while(tmp > 1) {
            int mifac = mi[tmp];
            int cnt = 0;
            prime_fac[i]++;
            while(tmp % mifac == 0) {
                tmp /= mifac;
                cnt++;
            }
            mul[i] *= (cnt + 1);
        }
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",mul[tmp] - prime_fac[tmp]);
    }
}