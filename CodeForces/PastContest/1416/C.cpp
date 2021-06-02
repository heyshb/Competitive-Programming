#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 300010;
const int MAXNODE = 300010 * 31;
typedef long long LL;
int ch[MAXNODE][2];
int dep[MAXNODE];
int cnt[MAXNODE];
LL rev[MAXNODE];
LL scnt[100], srev[100];
const int MD = 30;
int main() {
    int N,M = 1;
    dep[1] = 0;
    scanf("%d",&N);
    LL sumr = 0;
    for (int i=1;i<=N;i++) {
        int v;
        scanf("%d",&v);
        int now = 1;
        cnt[now]++;
        for (int j=MD;j>=0;j--) {
            int d = (v >> j) & 1;
            int &cd = ch[now][d];
            if (!cd) {
                cd = ++M;
                dep[M] = dep[now] + 1;
            }
            if (d == 0) rev[now] += cnt[ch[now][1]];
            now = cd;
            cnt[now]++;
        }
    }
    /*
    for (int i=1;i<=M;i++) {
        printf("%d %d %lld\n",i,cnt[i],rev[i]);
    }
    */
    for (int i=1;i<=M;i++) {
        sumr += rev[i];
        scnt[dep[i]] += 1LL * cnt[ch[i][0]] * cnt[ch[i][1]];
        srev[dep[i]] += rev[i];
    }
    LL b = 0;
    for (int i=0;i<=MD;i++) {
        if ((scnt[i] - srev[i]) < srev[i]) {
            sumr -= srev[i] - (scnt[i] - srev[i]);
            b ^= (1LL << (MD - i));
        }
    } 
    printf("%lld %lld\n",sumr,b);
}