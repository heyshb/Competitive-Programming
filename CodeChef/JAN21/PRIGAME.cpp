#include <bits/stdc++.h>

using namespace std;

int p[1000010], mi[1000010], cnt[1000010], sg[1000100];
vector<int> primes;
bool vis[1000];

int main() {
    int T, X, Y;
    int M = 1000000;
    for (int i=2;i<=M;i++) p[i] = 1;
    for (int i=2;i<=M;i++) {
        if (p[i]) {
            primes.push_back(i);
            mi[i] = i;
        }
        for (auto &t: primes) {
            if (i * t > M) break;
            p[i * t] = 0;
            mi[i * t] = t;
            if (i % t == 0) break;
        }
    }
    for (int i=1;i<=M;i++) {
        cnt[i] = 0;
        int tmp = i;
        while(tmp > 1) {
            int val = mi[tmp];
            cnt[i]++;
            while(tmp % val == 0) {
                tmp /= val;
            }
        }
        //if (i <= 30) printf("%d %d\n",i,cnt[i]);
    }
    sg[0] = 0;
    for (int i=1;i<=100;i++) {
        memset(vis, false, sizeof(vis));
        for (int j=1;j<=i;j++) {
            if (cnt[j] <= 2) {
                vis[sg[i - j]] = true;
            }
        }
        for (int j=0;;j++) {
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
        }
        printf("sg[%d] = %d\n",i,sg[i]);
    }
    /*
    for (int i=0;i<=20;i++) {
        printf("%d %d %d\n",i,primes[i],mi[i]);
    }
    */
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&X,&Y);
        if (X <= Y) {
            puts("Chef");
        } else {
            puts("Divyam");
        }
    }
}